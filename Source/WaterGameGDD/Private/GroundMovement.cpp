// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundMovement.h"

// Sets default values
AGroundMovement::AGroundMovement()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGroundMovement::BeginPlay()
{
	Super::BeginPlay();
}

/// <summary>
/// Connected to an event hit this will check if a player can jump based on it's tag
/// </summary>
/// <param name="ObjectActor">The player object that is being moved in the jump</param>
/// <param name="JumpableTagList">A list of all tags that can reset our jump</param>
void AGroundMovement::JumpCheck(AActor* ObjectActor, TArray<FName> JumpableTagList)
{
	for(FName Ltag : JumpableTagList)
	{
		if (ObjectActor->ActorHasTag(Ltag))
		{
			canJump = true;
		}
		else
		{
			canJump = false;
		}
	}
}

void AGroundMovement::WalkForward(UMeshComponent* Body, float speed, float maxSpeed)
{
		Body->AddImpulse(FVector(speed, 0, 0));
}

void AGroundMovement::WalkBackwards(UMeshComponent* Body, float speed, float maxSpeed)
{
	Body->AddImpulse(FVector(-speed, 0, 0));
}

void AGroundMovement::WalkLeft(UMeshComponent* Body, float speed, float maxSpeed)
{
	Body->AddImpulse(FVector(0, -speed, 0));
}

void AGroundMovement::WalkRight(UMeshComponent* Body, float speed, float maxSpeed)
{
	Body->AddImpulse(FVector(0, speed, 0));
}

// Called every frame
void AGroundMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGroundMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGroundMovement::GroundJump(UMeshComponent* Body, float JumpForce, int numJumps)
{
	if (numJumps >= jumpCount  && canJump)
	{
		Body->AddImpulse(FVector(0.0f, 0.0f, JumpForce * 10));
		canJump = false;
	}
}

