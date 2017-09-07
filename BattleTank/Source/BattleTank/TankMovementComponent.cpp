#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "GameFramework/Actor.h"

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

	// Overriding behavior
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();

	/*
		The dot product is the parellness of the vectors. If they are orthognal, the dot product is 0. 
		If they are parallel, it is 1, if parallel but facing the opposite directions: -1.
	*/

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	
	
	/*
		The cross product is the perpendicularity of the vectors. 
		If the are parallel then 0, if they are perpendicular then 1.

		ORDER MATTERS
	*/

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);

	// auto Time = FPlatformTime::Seconds();
	UE_LOG(LogTemp, Warning, TEXT("Right: %f Forward: %f"), RightThrow, ForwardThrow)
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	// TODO fix doubling of speed
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialise(UTankTrack * LeftTrack, UTankTrack * RightTrack) {
	if (!LeftTrack || !RightTrack) { return; }
	this->LeftTrack = LeftTrack;
	this->RightTrack = RightTrack;
}
