// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GroundMovement.generated.h"

UCLASS()
class WATERGAMEGDD_API AGroundMovement : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGroundMovement();
	UMeshComponent* myBody = nullptr;
	bool canJump = false;

private:
	int jumpCount = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UFUNCTION(BlueprintCallable, Category = "Ground Movement")
	void GroundJump(UMeshComponent* Body, float JumpForce, int numJumps);
	UFUNCTION(BlueprintCallable, Category = "Ground Movement")
	void JumpCheck(AActor* ObjectActor, TArray<FName> JumpableTagList);
};
