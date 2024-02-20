// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"

#include "Barracks.generated.h"

class UPaperFlipbook;
class UPaperFlipbookComponent;
UCLASS()
class HITPROJECT2D_API ABarracks : public ABuilding
{
	GENERATED_BODY()
public:


protected:
	virtual void LevelUp(float& NewLevel, float MaxLevel) override;
	virtual void DestroyLevel(float& BarracksCurrentLevel, float Building_HP) override;
	float LevelOfBarracks;
	float BaseDefenceValueofBarracks;
	float BaseHumanSize=10;

	void LevelStatsIncreaseBarracks(float& BarracksSize);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level10;



private:

	UPaperFlipbookComponent* BarracksFlipbookComponent;
	void SettingFlipbookComponent();

};
