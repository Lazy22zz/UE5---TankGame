// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"

ATower::Tower()
{

}

void ATower::BeginPlay()
{
    Super::BeginPlay();
}

void ATower::Tick(float DeltaTime)
{
    float range = FVector::Dist(GetActorLocation(), )
}