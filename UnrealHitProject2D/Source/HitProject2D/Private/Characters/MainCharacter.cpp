// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "PaperFlipbook.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"


AMainCharacter::AMainCharacter()
{
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 650.f;
	Camera->SetupAttachment(CameraBoom);
	/*WalkRight_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("WalkRight_Component"));
	WalkLeft_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("WalkLeft_Component"));
	WalkUp_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("WalkUp_Component"));
	WalkDown_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("WalkDown_Component"));

	IdleRight_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("IdleRight_Component"));
	IdleLeft_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("IdleLeft_Component"));
	IdleUp_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("IdleUp_Component"));
	IdleDefault_MeansDown_Component = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("IdleDefault_MeansDown_Component"));*/
	

	
}

void AMainCharacter::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("DirectionVector: (%f, %f)"), DirectionVector.X, DirectionVector.Y));
}
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (CharacterMappingContext)
			{
				Subsystem->AddMappingContext(CharacterMappingContext, 0);
			}
		}
	}

			
}
void AMainCharacter::Manipulation()
{

}

void AMainCharacter::PlayFlipbooksIdle()
{
		if (LastValue.X > 0.1f)
		{
			GetSprite()->SetFlipbook(IdleDefault_MeansDown);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Idle Up")));
		}
		else if (LastValue.X < -0.1f)
		{
			GetSprite()->SetFlipbook(IdleUp);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Idle Down")));
		}
		else if (LastValue.Y > 0.1f)
		{
			GetSprite()->SetFlipbook(IdleRight);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Idle Left")));
		}
		else if (LastValue.Y < -0.1f)
		{
			GetSprite()->SetFlipbook(IdleLeft);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Idle Right")));
		}
}

void AMainCharacter::FlipbooksAnimation(FVector Value)
{
	
	

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Przeszlo if")));
		/*//Setup Attachments of components to Root Component
		//1. Walk
		WalkRight_Component->SetupAttachment(RootComponent);
		WalkLeft_Component->SetupAttachment(RootComponent);
		WalkUp_Component->SetupAttachment(RootComponent);
		WalkDown_Component->SetupAttachment(RootComponent);

		//2.Idle
		IdleRight_Component->SetupAttachment(RootComponent);
		IdleLeft_Component->SetupAttachment(RootComponent);
		IdleUp_Component->SetupAttachment(RootComponent);
		IdleDefault_MeansDown_Component->SetupAttachment(RootComponent);*/

		if (WalkRight && WalkLeft && WalkUp && WalkDown && IdleRight && IdleLeft && IdleUp && IdleDefault_MeansDown)
		{
			DirectionVector = Value;
			DirectionVector = GetActorRotation().RotateVector(DirectionVector);
			

			if (DirectionVector.X > 0.1f)
			{
				GetSprite()->SetFlipbook(WalkDown);
				LastValue = FVector2D(1.0f, 0.0f);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Walk Dwon")));
			}
			else if (DirectionVector.X < -0.1f)
			{
				GetSprite()->SetFlipbook(WalkUp);
				LastValue = FVector2D(-1.0f, 0.0f);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Walk Up")));
			
			}
			else if (DirectionVector.Y > 0.1f)
			{
				GetSprite()->SetFlipbook(WalkLeft);
				LastValue = FVector2D(0.0f, 1.0f);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Walk Left")));
			}
			else if (DirectionVector.Y < -0.1f)
			{
				
				GetSprite()->SetFlipbook(WalkRight);
				LastValue = FVector2D(0.0f, -1.0f);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Walk Right")));
			}
			

		}
}

void AMainCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D DirectionValue = Value.Get<FVector2D>();
	//const FVector Direction(DirectionValue.X, DirectionValue.Y, 0.0f); // Wektor kierunku w p≥aszczyünie XY (gry 2D)
	const FVector Direction(DirectionValue.X, DirectionValue.Y, 0.0f);
	AddMovementInput(Direction, 1.0f);

	FlipbooksAnimation(Direction);

}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* PlayerEnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		PlayerEnhancedInputComponent->BindAction(CharacterMoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
		PlayerEnhancedInputComponent->BindAction(IdleAnimationTrig, ETriggerEvent::None, this, &AMainCharacter::PlayFlipbooksIdle);
		PlayerEnhancedInputComponent->BindAction(CharacterManipulation, ETriggerEvent::Triggered, this, &AMainCharacter::Manipulation);
		
	}
}




