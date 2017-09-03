// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include"Engine/World.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReferrence(UTankBarrel * BarrelToSet) {
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReferrence(UTankTurret* TurretToSet) {
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector WorldLocation, float LaunchSpeed) {
	if (!Barrel) { return; }

	FVector LaunchVelocity; // TossVelocity
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bTargetable = UGameplayStatics::SuggestProjectileVelocity(
		this,
		LaunchVelocity,
		StartLocation,
		WorldLocation,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace // Must be present, otherwise bug
	);

	if (bTargetable) {
		auto AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto TankName = GetOwner()->GetName();
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	// Move Barrel
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto BarrelDeltaRotator = AimDirection.Rotation() - BarrelRotator;
	Barrel->ElevateBarrel(BarrelDeltaRotator.Pitch);
	
	// Move Turret
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto TurretDeltaRotator = AimDirection.Rotation() - TurretRotator;
	Turret->RotateTurret(TurretDeltaRotator.Yaw);
}

