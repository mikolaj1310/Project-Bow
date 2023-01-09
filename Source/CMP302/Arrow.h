// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Arrow.generated.h"

UENUM(BlueprintType)
enum class ArrowStateC : uint8
{
	AS_None UMETA(DisplayName = "None"),
	AS_OnGround UMETA(DisplayName = "OnGround"),
	AS_InAir UMETA(DisplayName = "InAir"),
	AS_InBow UMETA(DisplayName = "InBow")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class CMP302_API AArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UStaticMeshComponent* arrowMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void SetArrowMesh(UStaticMeshComponent* mesh);

	UFUNCTION(BlueprintCallable)
		void SetArrowStateC(ArrowStateC as);

	UFUNCTION(BlueprintCallable)
		void OnStateEndC(ArrowStateC as);

	UFUNCTION(BlueprintCallable)
		void OnStateBeginC(ArrowStateC as);

	UFUNCTION(BlueprintCallable)
		void HandleOverlapC(AActor* character, FHitResult hit);

	UFUNCTION(BlueprintCallable)
		void FireArrowC(float charge);

	UPROPERTY(BlueprintReadWrite)
		ArrowStateC currentState = ArrowStateC::AS_None;

	UPROPERTY(BlueprintReadWrite)
		float bowCharge = 0;

	UPROPERTY(BlueprintReadWrite)
		class UProjectileMovementComponent* projectileComponentC;
	//TSubobjectPtr<class UProjectileMovementComponent> projectileComponent;

	float grav = 0;
};
