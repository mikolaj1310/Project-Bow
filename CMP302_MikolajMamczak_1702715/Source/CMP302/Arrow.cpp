// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"

// Sets default values
AArrow::AArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileComponentC = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	grav = projectileComponentC->ProjectileGravityScale;
	projectileComponentC->ProjectileGravityScale = 0;
	projectileComponentC->Velocity = FVector::ZeroVector;

}

// Called when the game starts or when spawned
void AArrow::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//projectileComponentC->Velocity = FVector(0, 0, 0);
}

void AArrow::SetArrowMesh(UStaticMeshComponent* mesh)
{
	arrowMesh = mesh;
}

void AArrow::SetArrowStateC(ArrowStateC as)
{
	if (as != currentState)
	{
		OnStateEndC(currentState);
		currentState = as;
		OnStateBeginC(currentState);
	}
}

void AArrow::OnStateEndC(ArrowStateC as)
{
	if (currentState == ArrowStateC::AS_InAir)
	{
		projectileComponentC->DestroyComponent();
	}
}

void AArrow::OnStateBeginC(ArrowStateC as)
{
	if (currentState == ArrowStateC::AS_OnGround)
	{
		arrowMesh->SetCollisionProfileName("OverlapAllDynamic");
	}
	else if (currentState == ArrowStateC::AS_InBow)
	{
		arrowMesh->SetCollisionProfileName("NoCollision");
	}
	else if (currentState == ArrowStateC::AS_InAir)
	{
		arrowMesh->SetCollisionProfileName("OverlapAllDynamic");
		
		projectileComponentC->Velocity = FVector::ZeroVector;
		projectileComponentC->ProjectileGravityScale = grav;
		
		projectileComponentC->Velocity = GetActorForwardVector() * FMath::Lerp(100.f, 4000.f, bowCharge);
		projectileComponentC->bRotationFollowsVelocity = true;
	}
}

void AArrow::HandleOverlapC(AActor* actor, FHitResult hit)
{
	if (currentState == ArrowStateC::AS_OnGround)
	{
		//if (Cast<FirstPersonCharacter>(actor))
		//{
		//
		//}
		//ABowCharacter* character = Cast<FirstPersonC>(actor);
		//if (character)
		//{
		//	character->AddArrow(1);
		//	Destroy();
		//}
	}
	else if (currentState == ArrowStateC::AS_InAir)
	{
		//if (!Cast<ABowCharacter>(actor))
		//{
		//	SetArrowStateC(ArrowStateC::UIM_OnGround);
		//
		//	FVector hitLocation = hit.Location + (GetActorForwardVector() * 40);
		//	SetActorLocation(hitLocation);
		//
		//	AttachToActor(actor, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));
		//}
	}
}

void AArrow::FireArrowC(float charge)
{
	bowCharge = charge;
	SetArrowStateC(ArrowStateC::AS_InAir);
}
