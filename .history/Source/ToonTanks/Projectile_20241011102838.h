// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Projectile.generated.h"


UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category= "Movement")
	class UProjectileMovementComponent* ProjectileMoveComp;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "Damage Amount")
	float Damage_Amount = 50.f;

	UPROPERTY(EditAnywhere, Category = "combat")
	class UParticleSystem* HitParticle;

	UPROPERTY(VisibleAnywhere, Category = "combat")
	class UParticleSystemComponent* ParticleSysCom;

	UPROPERTY(EditAnywhere, Category = "combat")
	class USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "combat")
	class USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "combat")
	TSubclassof< class UCameraShakeBase> HitCameraShakeClass;
};
