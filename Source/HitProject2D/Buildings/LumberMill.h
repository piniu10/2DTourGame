// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "LumberMill.generated.h"

class UPaperFlipbook;
class UPaperFlipbookComponent;

UCLASS()
class HITPROJECT2D_API ALumberMill : public ABuilding
{
	GENERATED_BODY()
public:

protected:
	virtual void LevelUp(float& NewLevel, float MaxLevel) override;
	virtual void DestroyLevel(float& LevelOfLumberMill, float Building_HP) override;

	void LevelStatsIncreaseLumberMill(float& LumberMillSize);

	float CurrentLevelOfLumberMill;
	float BaseDefenceValueofLumberMill;
	float BaseWoodProduction = 6;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level10;

private:

	UPaperFlipbookComponent* LumberMillFlipbookComponent;
	void SettingFlipbookComponent();

};
