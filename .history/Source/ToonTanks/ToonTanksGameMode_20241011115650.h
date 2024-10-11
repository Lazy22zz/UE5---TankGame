// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"


/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameStartWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);	

private:
	class ATank* Tank;

	class AToonTanksPlayerController* ToonTanksPlayerController;
	
	void GameStart();
	float Time_Start = 3.f;

	int32 Num_Towers = 0;
	int32 GetTowerCount();

	
};
