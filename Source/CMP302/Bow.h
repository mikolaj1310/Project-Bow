// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Arrow.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bow.generated.h"

UCLASS()
class CMP302_API ABow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//stores the arrow currently attached to the bow
	UPROPERTY(BlueprintReadWrite)
	AArrow* arrowC;

	//stores how charged the bow currently is
	UPROPERTY(BlueprintReadWrite)
	float chargeAmountC;

	//function for reloading bow
	UFUNCTION(BlueprintCallable)
	void ReloadC();

	//function for firing the arrow
	UFUNCTION(BlueprintCallable)
	void FireArrowC();

	//used for spawning a new arrow after it has been fired
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> actorToSpawn;

private:
};
