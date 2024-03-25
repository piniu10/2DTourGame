// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"

#include "IronWorks.generated.h"

class UPaperFlipbook;
class UPaperFlipbookComponent;

UCLASS()
class HITPROJECT2D_API AIronWorks : public ABuilding
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

protected:
	virtual void LevelUp(float NewLevel, float MaxLevel) override;
	virtual void DestroyLevel(float LevelOfIronWorks, float Building_HP) override;
	void LevelStatsIncreaseIronWorks(float& IronWorksSize);

	float CurrentLevelOfIronWorks;
	float BaseDefenceValueofIronWorks;
	float BaseIronProduction = 6;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UPaperFlipbook* Level10;

private:

	UPaperFlipbookComponent* IronWorksFlipbookComponent;
	void SettingFlipbookComponent();
};
