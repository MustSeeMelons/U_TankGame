// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController {
	GENERATED_BODY()
private:
	ATank* PlayerTank;
public:
	float AcceptanceRadius = 3000;
	virtual void BeginPlay() override; // already virtual in parent, for readability
	virtual void Tick(float DeltaTime) override;
};
