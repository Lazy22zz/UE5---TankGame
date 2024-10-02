// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	ATower();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


private:
	class ATank* Tank;
	
	class ATower* Tower;

	UPROPERTY(EditAnywhere, category = "FireRange")
	float FireRange = 300.f;
};
