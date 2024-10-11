// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); // 0 means playerInt

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true); // true means enable loop

}

void ATower::Tick(float DeltaTime)
{
    if (InFireRange())
    {
        RotateTurret(Tank -> GetActorLocation());
    }
    
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy(); // enable tower died
}

void ATower::CheckFireCondition()
{
    if (Tank == nullptr)
    {
        return;
    }
    if (InFireRange() && Tank -> bAlive == true)
    {
        Fire();
    }
    
}

bool ATower::InFireRange()
{
    if (Tank)
    {
        float range = FVector::Dist(GetActorLocation(), Tank -> GetActorLocation());
        if (FireRange >= range)
        {
            return true;
        }
    }

    return false;
}