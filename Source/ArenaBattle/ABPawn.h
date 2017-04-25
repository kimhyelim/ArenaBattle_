// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "ABPawn.generated.h"

UCLASS(config = Game)
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class UCapsuleComponent* Body;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
	class UFloatingPawnMovement* Movement;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(config, BlueprintReadWrite, EditAnywhere, Category = "Stat")
	float MaxHP;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Stat")
	float CurrentHP;

	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
	//	class UFloatingPawnMovement* Movement;
public:
	UPROPERTY(config,BlueprintReadWrite, VisibleInstanceOnly, Category = "Asset")
		TArray<FStringAssetReference> CharacterAssets;
//private:
	float CurrentLeftRightVal;
	float CurrentUpDownVal;

	UFUNCTION()
		void UpDownInput(float NewInputVal);

	UFUNCTION()
		void LeftRightInput(float NewInputval);
};
