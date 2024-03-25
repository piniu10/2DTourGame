// Fill out your copyright notice in the Description page of Project Settings.


#include "Brickyard.h"
class UPaperFlipBook;
void ABrickyard::LevelUp(float NewLevel, float MaxLevel)
{
	MaxLevel = 10;
	NewLevel = CurrentLevelOfBrickyard;
	if (CurrentLevelOfBrickyard == 1)
	{
		//zmiana meshu

	}
	if (CurrentLevelOfBrickyard == 5)
	{
		//Zmiana meshu 2
	}
	if (CurrentLevelOfBrickyard == MaxLevel)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
	}
	if (CurrentLevelOfBrickyard != MaxLevel)
	{
		LevelStatsIncreaseBrickyard(CurrentLevelOfBrickyard);
	}
}

void ABrickyard::DestroyLevel(float LevelOfBrickyard, float Building_HP)
{
	Super::DestroyLevel(LevelOfBrickyard, Building_HP);

	LevelOfBrickyard = CurrentLevelOfBrickyard;

	if (CurrentLevelOfBrickyard < 10)
	{
		//zmiana meshu

	}
	if (CurrentLevelOfBrickyard < 5)
	{
		//Zmiana meshu 2
	}
	if (CurrentLevelOfBrickyard < 1)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
	}
}

void ABrickyard::LevelStatsIncreaseBrickyard(float& BrickyardSize)
{

}
