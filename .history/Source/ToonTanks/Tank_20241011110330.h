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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	// get private playercontroller 
	APlayerController* GetTankPlayerController() const;

	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmCom;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true") )
	float speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true") )
	float TurnRate;
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// user input
	void Move(float value);
	// user input
	void Turn(float value);

	// enable playercontroller
	APlayerController* TankPlayerController;

	

};
