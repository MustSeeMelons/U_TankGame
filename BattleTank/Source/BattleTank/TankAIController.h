// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	ATank* PlayerTank;
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override; // already virtual in parent, for readability
	ATank* GetPlayerTank() const;
};
