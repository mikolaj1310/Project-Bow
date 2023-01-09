// Fill out your copyright notice in the Description page of Project Settings.


#include "Bow.h"

// Sets default values
ABow::ABow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABow::ReloadC()
{
	//set up spawn parameters for the new arrow
	FActorSpawnParameters spawnInfo;
	FRotator rot(0, 0, 0);
	FVector pos(0, 0, 0);
	
	//spawn an arrow using spawn parameters
	arrowC = GetWorld()->SpawnActor<AArrow>(actorToSpawn, pos, rot, spawnInfo);
	
	//set arrow state to assigned to bow
	arrowC->currentState = ArrowStateC::AS_InBow;
	
	FAttachmentTransformRules rules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
	arrowC->AttachToComponent(FindComponentByClass<USkeletalMeshComponent>(), rules, FName(TEXT("Arrow_Socket")));
}

void ABow::FireArrowC()
{
	if (arrowC)
	{
		FDetachmentTransformRules rules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false);
		arrowC->DetachFromActor(rules);
		arrowC->FireArrowC(chargeAmountC);

	}
}
