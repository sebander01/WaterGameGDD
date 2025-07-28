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

/// <summary>
/// Allows the player to walk forwards
/// </summary>
/// <param name="Body">The UMeshComponent of the player body that we want to move</param>
/// <param name="speed">How fast we move per method run</param>
/// <param name="maxSpeed">The absolute max speed we can move in that direction</param>
void AGroundMovement::WalkForward(UMeshComponent* Body, float speed, float maxSpeed)
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().X <= maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(speed, 0, 0));
	}
}

/// <summary>
/// Allows the player to walk backwards
/// </summary>
/// <param name="Body">The UMeshComponent of the player body that we want to move</param>
/// <param name="speed">How fast we move per method run</param>
/// <param name="maxSpeed">The absolute max speed we can move in that direction</param>
void AGroundMovement::WalkBackwards(UMeshComponent* Body, float speed, float maxSpeed)
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().X >= -maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(-speed, 0, 0));
	}
}

/// <summary>
/// Allows the player to walk left
/// </summary>
/// <param name="Body">The UMeshComponent of the player body that we want to move</param>
/// <param name="speed">How fast we move per method run</param>
/// <param name="maxSpeed">The absolute max speed we can move in that direction</param>
void AGroundMovement::WalkLeft(UMeshComponent* Body, float speed, float maxSpeed)
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().Y >= -maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(0, -speed, 0));
	}
}

/// <summary>
/// Allows the player to walk right
/// </summary>
/// <param name="Body">The UMeshComponent of the player body that we want to move</param>
/// <param name="speed">How fast we move per method run</param>
/// <param name="maxSpeed">The absolute max speed we can move in that direction</param>
void AGroundMovement::WalkRight(UMeshComponent* Body, float speed, float maxSpeed)
{
	//Checks if the player is within the speed limit for standard movement
	if (Body->GetPhysicsLinearVelocity().Y <= maxSpeed)
	{
		//Adds an impulse force to allow us to move the player
		Body->AddImpulse(FVector(0, speed, 0));
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

/// <summary>
/// Allows the player to jump
/// </summary>
/// <param name="Body">The player body that we want to move</param>
/// <param name="JumpForce">The force that we jump at</param>
/// <param name="numJumps">How many times we can jump</param>
void AGroundMovement::GroundJump(UMeshComponent* Body, float JumpForce, int numJumps)
{
	//If we are able to jump
	if (numJumps >= jumpCount  && canJump)
	{
		//Add a force to the player body that pushes the player up and then multiple by 10 + the linear velocity of x so a player running jumps with more force
		Body->AddImpulse(FVector(0.0f, 0.0f, JumpForce * 10 + Body->GetPhysicsLinearVelocity().X));
		//Set can jump to false this will reset when we touch a valid object
		canJump = false;
	}
}

