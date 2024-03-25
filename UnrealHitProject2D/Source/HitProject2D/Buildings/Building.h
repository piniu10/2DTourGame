// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"

class UPaperFlipbook;
class UPaperFlipbookComponent;

UCLASS()
class HITPROJECT2D_API ABuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilding();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void LevelUp(float NewLevel, float MaxLevel);

	virtual void DestroyLevel(float LevelOfBuilding, float Building_HP);


	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
