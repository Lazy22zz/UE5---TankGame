// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{

}

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();

    Tank = cast<ATank>(UGameplayStatics::GetPlayerPawn());
}