// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ATank::ATank()
{
    SpringArmCom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArmCom -> SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera -> SetupAttachment(SpringArmCom);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent -> BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::Move(float value)
{
    UE_LOG(LogTemp, Display, TEXT("Move: %f"), value);
    FVector DeltaLocation = FVector::ZeroVector; // x,y,z is 0
    DeltaLocation.X = value * DeltaTime * speed;
    AddActorLocalOffset(DeltaLocation);

}