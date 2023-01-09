// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Arrow.h"
#include "CoreMinimal.h"
//#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class CMP302_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//posiiton of the target center
	UPROPERTY(BlueprintReadWrite)
		FVector targetCenterC;

	//amount to be added to the score after check
	UPROPERTY(BlueprintReadWrite)
		int scoreAmountC;

	//checks the distance between the center of the target and where the arrow hit
	UFUNCTION(BlueprintCallable)
		void HandleTargetOverlap(AArrow* arrow);

	//target mesh
	UPROPERTY(BlueprintReadWrite)
		class UStaticMeshComponent* targetMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
