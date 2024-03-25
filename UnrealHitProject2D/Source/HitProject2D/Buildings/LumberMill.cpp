// Fill out your copyright notice in the Description page of Project Settings.


#include "LumberMill.h"

class UPaperFlipBook;

void ALumberMill::LevelUp(float NewLevel, float MaxLevel)
{
	MaxLevel = 10;
	NewLevel = CurrentLevelOfLumberMill;
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

void ALumberMill::DestroyLevel(float LevelOfLumberMill, float Building_HP)
{
	Super::DestroyLevel(LevelOfLumberMill, Building_HP);

	LevelOfLumberMill = CurrentLevelOfLumberMill;

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
