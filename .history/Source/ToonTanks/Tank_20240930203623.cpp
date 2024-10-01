// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Chaos/DebugDrawQueue.h"

ATank::ATank()
{
    SpringArmCom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArmCom -> SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera -> SetupAttachment(SpringArmCom);
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(PlayerControllerRef)
    {
        FHitResult HitResult;
        PlayerControllerRef -> GetHitResultUnderCursor(
            ECollisionChannel::ECC_Visibility,
            false,
            HitResult
        );
        
        /*DrawDebugSphere(GetWorld(),
            HitResult.ImpactPoint,
            25.f,
            12,
            FColor::Red,
            false,
            -1.f);
        }*/
        
        RotateTurret(HitResult.ImpactPoint);
    }

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

    PlayerControllerRef = Cast<APlayerController>(GetController());

	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent -> BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent -> BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float value)
{
    FVector DeltaLocation = FVector::ZeroVector; // x,y,z is 0
    DeltaLocation.X = value * UGameplayStatics::GetWorldDeltaSeconds(this) * speed;
    AddActorLocalOffset(DeltaLocation, true);

}

void ATank::Turn(float value)
{
    FRotator DeltaRotation = FRotator::ZeroRotator;
    DeltaRotation.Yaw = value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;
    AddActorLocalRotation(DeltaRotation, true);
    
}