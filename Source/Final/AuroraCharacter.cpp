// Fill out your copyright notice in the Description page of Project Settings.


#include "AuroraCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Animation/AnimInstance.h"

// Sets default values
AAuroraCharacter::AAuroraCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Speed = 0;
	SprintSpeed = 800;
	WalkSpeed = 600;
	score = 0;
	Coins = 0;


	CameraBoom =
		CreateDefaultSubobject<USpringArmComponent>
		(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	CameraBoom->bUsePawnControlRotation = true;



	FollowCamera =
		CreateDefaultSubobject<UCameraComponent>
		(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom,
		USpringArmComponent::SocketName);

	/*bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;*/


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f,
		540.0f, 0.0f);
	GetCharacterMovement()->MaxAcceleration = 1000;

}

// Called when the game starts or when spawned
void AAuroraCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuroraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAuroraCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForwardBackward", this, &AAuroraCharacter::MoveForwardBackward);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &AAuroraCharacter::MoveLeftRight);
	PlayerInputComponent->BindAxis("LookUpDown", this,
		&APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookLeftRight", this,
		&APawn::AddControllerYawInput);
	

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AAuroraCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AAuroraCharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AAuroraCharacter::SprintStart);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AAuroraCharacter::SprintStop);

}


void AAuroraCharacter::MoveForwardBackward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get forward vector
		const FVector Direction =
			FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}


void AAuroraCharacter::MoveLeftRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get right vector
		const FVector Direction =
			FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);

	}
}


void AAuroraCharacter::AddCoin() {
	score += 10;
	UE_LOG(LogTemp, Warning, TEXT("Score : %d"), score);


}

void AAuroraCharacter::SprintStart() {

	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

	return;
}

void AAuroraCharacter::SprintStop() {
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	return;
}
