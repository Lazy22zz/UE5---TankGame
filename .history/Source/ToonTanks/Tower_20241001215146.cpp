// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "kismet/UGamePlayerStatic.h"

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tower = cast<ATower>(UGamePlayStatic::GetPlayerPawn(this, 0));

    Tank = cast<ATank>(UGamePlayStatic::GetPlayerPawn(this, 0)); // 0 means playerInt
}

void ATower::Tick(float DeltaTime)
{
    if (Tank)
    {
        float range = FVector::Dist(Tower -> GetActorLocation(), Tank -> GetActorLocation());
        if (FireRange >= range)
        {
            FVector Toward_Direction = Tank - Tower;
            RotateTurret(Toward_Direction);
        }

    }
    
}