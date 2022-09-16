// Fill out your copyright notice in the Description page of Project Settings.

#include "RogueCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ARogueCharacter::ARogueCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	SpringArmComp-> SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera component");
	CameraComp->SetupAttachment(SpringArmComp);
} 

// Called when the game starts or when spawned
void ARogueCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARogueCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARogueCharacter::ForwardBack(float Value) {
	AddMovementInput(GetActorForwardVector(), Value);
}

void ARogueCharacter::Turn(float value) {

}

// Called to bind functionality to input
void ARogueCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("ForwardBack", this, &ARogueCharacter::ForwardBack);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

