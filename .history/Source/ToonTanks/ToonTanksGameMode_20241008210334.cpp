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
        -- Num_Towers;
        if (Num_Towers == 0)
        {
            GameOver(true);
        }
    }
}

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();

    GameStart();

}

void AToonTanksGameMode::GameStart()
{
    Num_Towers = GetTowerCount();
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

int32 AToonTanksGameMode::GetTowerCount()
{
    TArray<AActor*> Towers;
    Num_Towers = UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);
    return Towers.Num();
}