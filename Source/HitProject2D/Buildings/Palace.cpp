// Fill out your copyright notice in the Description page of Project Settings.

#include "Palace.h"
#include "PaperFlipbook.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"

class UPaperFlipbook;
void APalace::LevelUp(float& NewLevel, float MaxLevel)
{
	Super::LevelUp(CurrentLevelOfPalace, MaxLevel);

	if (CurrentLevelOfPalace == 1)
	{
		//zmiana meshu
		VillageLevel = 1;
	}
	if (CurrentLevelOfPalace == 2)
	{
		//Zmiana meshu 2
		VillageLevel = 2;
	}
	if (CurrentLevelOfPalace == MaxLevel)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
		VillageLevel = 3;
	}

}

void APalace::DestroyLevel(float& LevelOfPalace, float Building_HP)
{
	Super::DestroyLevel(LevelOfPalace, Building_HP);



}

void APalace::SettingFlipbookComponent()
{
	PalaceFlipbookComponent = FindComponentByClass<UPaperFlipbookComponent>();
}

