// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); // 0 means playerInt

}

void ATower::Tick(float DeltaTime)
{
    if (Tank)
    {
        float range = FVector::Dist(GetActorLocation(), Tank -> GetActorLocation());
        if (FireRange >= range)
        {
            RotateTurret(Tank -> GetActorLocation());
        }

    }
    
}