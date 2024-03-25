// Fill out your copyright notice in the Description page of Project Settings.

#include "Barracks.h"
#include "PaperFlipbook.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"


void ABarracks::LevelUp(float NewLevel, float MaxLevel)
{
	Super::LevelUp(NewLevel, MaxLevel);
	
	MaxLevel = 10;
	NewLevel = LevelOfBarracks;
	if (LevelOfBarracks == 1)
	{
		//zmiana meshu
		
	}
	if (LevelOfBarracks == 5)
	{
		//Zmiana meshu 2
	}
	if (LevelOfBarracks==MaxLevel)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
	}
	if (LevelOfBarracks!=MaxLevel)
	{
		LevelStatsIncreaseBarracks(LevelOfBarracks);
	}

}

void ABarracks::DestroyLevel(float BarracksCurrentLevel, float Building_HP)
{
	Super::DestroyLevel(BarracksCurrentLevel, Building_HP);

	BarracksCurrentLevel = LevelOfBarracks;
	
	if (LevelOfBarracks < 10)
	{
		//zmiana meshu

	}
	if (LevelOfBarracks <5)
	{
		//Zmiana meshu 2
	}
	if (LevelOfBarracks <1)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
	}
}

void ABarracks::LevelStatsIncreaseBarracks(float& BarracksSize)
{
	float HumanMultiplier=1.25;
	BaseHumanSize = BaseHumanSize + BarracksSize * HumanMultiplier;

}

