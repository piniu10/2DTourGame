// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Gamemode1.generated.h"

/**
 * 
 */
UCLASS()
class HITPROJECT2D_API AGamemode1 : public AGameModeBase
{
	GENERATED_BODY()

public:

	AGamemode1();

	virtual void Tick(float DeltaTime) override;
protected:

	virtual void BeginPlay() override;

private:

	
};
