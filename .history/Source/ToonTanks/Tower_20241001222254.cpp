// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
    Tower = nullptr; // Initialize pointer if needed
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); // 0 means playerInt

}

void ATower::Tick(float DeltaTime)
{
    if (Tank && Tower)
    {
        float range = FVector::Dist(Tower -> GetActorLocation(), Tank -> GetActorLocation());
        if (FireRange >= range)
        {
            RotateTurret(Tank -> GetActorLocation());
        }

    }
    
}