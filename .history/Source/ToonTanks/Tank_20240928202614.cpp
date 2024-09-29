// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

ATank::ATank()
{
    SpringArmCom = CreateDefaultSubobject<SpringArmComponent>(TEXT("Spring Arm"));
    SpringArmCom -> SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera -> SetupAttachment(SpringArmCom);
}