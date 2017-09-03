// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include"Engine/World.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto ClampedNewElevation = FMath::Clamp(RawNewElevation, MinElevation, MaxElevation);
	
	SetRelativeRotation(FRotator(ClampedNewElevation, 0, 0));
}


