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

void AGroundMovement::JumpCheck(AActor* ObjectActor, TArray<FName> JumpableTagList)
{
	for(FName Ltag : JumpableTagList)
	{
		UE_LOG(LogTemp, Error, TEXT("Jump Check"))
		if (ObjectActor->ActorHasTag(Ltag))
		{
			UE_LOG(LogTemp, Error, TEXT("Hit"));
			canJump = true;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Fail"))
			canJump = false;
		}
	}
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
	UE_LOG(LogTemp, Error, TEXT("Pressed"));
	if (numJumps >= jumpCount  && canJump)
	{
		UE_LOG(LogTemp, Error, TEXT("Jump"));
		Body->AddImpulse(FVector(0.0f, 0.0f, JumpForce * 10));
		canJump = false;
	}
}

