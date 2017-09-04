// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;

class UTankBarrel;

class UTankTurret;

class AProjectile;

class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn {
	GENERATED_BODY()
private:
	UTankBarrel* Barrel = nullptr;
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
public:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReferrence(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReferrence(UTankTurret* TurretToSet);

	// Defaults
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;
};
