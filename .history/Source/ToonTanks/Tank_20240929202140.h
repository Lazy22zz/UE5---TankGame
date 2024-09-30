// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"


/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmCom;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed", meta = (AllowPrivateAccess = "true") )
	float speed;
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// user input
	void Move(float value);

};
