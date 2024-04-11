// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Character.h"
#include "AuroraCharacter.generated.h"

UCLASS()
class FINAL_API AAuroraCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category =
		Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category =
		Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;




public:
	// Sets default values for this character's properties
	AAuroraCharacter();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"PlayerStats")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"PlayerMovement")
		float SprintSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"PlayerMovement")
		float WalkSpeed;


	FORCEINLINE int32 GetCopperCoins() { return CopperCoins; }
	FORCEINLINE void SetCopperCoins(int32 coins) {
		CopperCoins = coins;
	}
	FORCEINLINE int32 GetSilverCoins() { return SilverCoins; }
	FORCEINLINE void SetSilverCoins(int32 coins) {
		SilverCoins = coins;
	}

	FORCEINLINE int32 GetGoldCoins() { return GoldCoins; }
	FORCEINLINE void SetGoldCoins(int32 coins) {
		GoldCoins = coins;
	}

	UFUNCTION()
		void AddCoin();



protected:
	// Called when the game starts or when spawned
	int32 score;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveLeftRight(float Value);

	void MoveForwardBackward(float Value);

	void SprintStart();
	void SprintStop();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"PlayerStats")
		int32 CopperCoins;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"PlayerStats")
		int32 SilverCoins;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"PlayerStats")
		int32 GoldCoins;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"PlayerStats")
		int32 Coins;

	



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
