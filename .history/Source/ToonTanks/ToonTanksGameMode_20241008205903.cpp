// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanksPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
    if(DeadActor == Tank)
    {
        Tank -> HandleDestruction();
        if (ToonTanksPlayerController)
        {
            ToonTanksPlayerController -> SetPlayerEnabledState(false);
        }
        GameOver(false);
    }
    else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
    {
        DestroyedTower -> HandleDestruction();
        TArray<AActor*> Towers;
        Num_Towers = UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers.Num());
    }
}

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();

    GameStart();

}

void AToonTanksGameMode::GameStart()
{
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this,0));

    GameStartWidget();

    if(ToonTanksPlayerController)
    {
        ToonTanksPlayerController -> SetPlayerEnabledState(false);

        FTimerHandle PlayerEnableTimerHandle;

        FTimerDelegate PlayerInputDelegate = FTimerDelegate::CreateUObject(
            ToonTanksPlayerController, 
            &AToonTanksPlayerController::SetPlayerEnabledState, 
            true
        );

        GetWorldTimerManager().SetTimer(
            PlayerEnableTimerHandle,
            PlayerInputDelegate,
            Time_Start,
            false
        );
    }
}