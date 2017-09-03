// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController player pawn name: %s"), *PlayerTank->GetName());
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find players pawn!"));
	}
}

ATank * ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	auto PlayerTank = GetPlayerTank();
	auto ControlledTank = GetControlledTank();
	if (PlayerTank && ControlledTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	}
}



