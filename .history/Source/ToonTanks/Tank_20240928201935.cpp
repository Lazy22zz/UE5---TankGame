// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

SpringArmCom = CreateDefaultSubobject<SpringArmComponent>(TEXT("Spring Arm"));
RootComponent = SpringArmCom;

Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));