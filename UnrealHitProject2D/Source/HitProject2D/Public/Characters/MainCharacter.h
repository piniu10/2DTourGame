

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "PaperCharacter.h"
#include "MainCharacter.generated.h"



class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class UPaperFlipbookComponent;
class UPaperFlipbook;

UCLASS()
class HITPROJECT2D_API AMainCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* CharacterMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* CharacterMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* CharacterManipulation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IdleAnimationTrig;

	//Idle FlipBooks Components
	
	/*UPaperFlipbookComponent* IdleDefault_MeansDown_Component;
	UPaperFlipbookComponent* IdleUp_Component;
	UPaperFlipbookComponent* IdleLeft_Component;
	UPaperFlipbookComponent* IdleRight_Component;

	//Walk FlipBooks Components
	UPaperFlipbookComponent* WalkUp_Component;
	UPaperFlipbookComponent* WalkDown_Component;
	UPaperFlipbookComponent* WalkLeft_Component;
	UPaperFlipbookComponent* WalkRight_Component;*/
	FVector DirectionVector;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Flipbook)
	UPaperFlipbook* IdleDefault_MeansDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Flipbook)
	UPaperFlipbook* IdleUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Flipbook)
	UPaperFlipbook* IdleLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Flipbook)
	UPaperFlipbook* IdleRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flipbook)
	UPaperFlipbook* WalkUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flipbook)
	UPaperFlipbook* WalkDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Flipbook)
	UPaperFlipbook* WalkLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Flipbook)
	UPaperFlipbook* WalkRight;


private:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;
	
	void Move(const FInputActionValue& Value);
	void Manipulation();
	void FlipbooksAnimation(FVector Value);
	void PlayFlipbooksIdle();

	FVector2D LastValue;
};
