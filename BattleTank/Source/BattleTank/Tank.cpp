// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include"Engine/World.h"
#include "UObject/UObjectGlobals.h"

// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire() {
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f, Tank firing!"), Time);
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::SetBarrelReferrence(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrelReferrence(BarrelToSet);
}

void ATank::SetTurretReferrence(UTankTurret* TurretToSet) {
	TankAimingComponent->SetTurretReferrence(TurretToSet);
}

