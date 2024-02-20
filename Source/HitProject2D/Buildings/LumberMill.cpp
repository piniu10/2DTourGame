// Fill out your copyright notice in the Description page of Project Settings.


#include "LumberMill.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"



void ALumberMill::LevelUp(float& NewLevel, float MaxLevel)
{
	Super::LevelUp(CurrentLevelOfLumberMill, MaxLevel);
	MaxLevel = 10;
	if (CurrentLevelOfLumberMill == 1)
	{
		//zmiana meshu

	}
	if (CurrentLevelOfLumberMill == 5)
	{
		//Zmiana meshu 2
	}
	if (CurrentLevelOfLumberMill == MaxLevel)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
	}
	if (CurrentLevelOfLumberMill != MaxLevel)
	{
		LevelStatsIncreaseLumberMill(CurrentLevelOfLumberMill);
	}
}

void ALumberMill::DestroyLevel(float& LevelOfLumberMill, float Building_HP)
{
	Super::DestroyLevel(CurrentLevelOfLumberMill, Building_HP);


	if (CurrentLevelOfLumberMill < 10)
	{
		//zmiana meshu

	}
	if (CurrentLevelOfLumberMill < 5)
	{
		//Zmiana meshu 2
	}
	if (CurrentLevelOfLumberMill < 1)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
	}
}

void ALumberMill::LevelStatsIncreaseLumberMill(float& LumberMillSize)
{

}

void ALumberMill::SettingFlipbookComponent()
{
	LumberMillFlipbookComponent = FindComponentByClass<UPaperFlipbookComponent>();
}
