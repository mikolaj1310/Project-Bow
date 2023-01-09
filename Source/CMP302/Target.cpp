// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	targetCenterC = FVector(0.0f, 0.0f, 5.0f);
	
}

void ATarget::HandleTargetOverlap(AArrow* arrow)
{
	//used for the final calculation representing the distance from the center of the target
	float distanceFromCenter = 0;
	//gets the arrow's tip as the point of coliision
	FVector forwardVec = arrow->GetActorForwardVector() * 170.0f;
	forwardVec = arrow->GetTargetLocation() + forwardVec;
	//stores the point of collision
	FVector point;
	targetMesh->GetClosestPointOnCollision(forwardVec, point);
	point = targetMesh->GetComponentLocation() - point;

	//calculation for determining how far the point of collision is from the target center
	distanceFromCenter = sqrt((pow((point.Y - targetCenterC.Y), 2) + pow((point.Z - targetCenterC.Z), 2)));
	
	//increment score based on distance calculation
	if (distanceFromCenter < 15)
		scoreAmountC = 10;
	else if (distanceFromCenter < 50)
		scoreAmountC = 5;
	else if (distanceFromCenter < 80)
		scoreAmountC = 2;
	else
		scoreAmountC = 1;
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

