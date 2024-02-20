// Fill out your copyright notice in the Description page of Project Settings.


#include "IronWorks.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"

void AIronWorks::BeginPlay()
{
	Super::BeginPlay();
	SettingFlipbookComponent();
}

void AIronWorks::LevelUp(float& NewLevel, float MaxLevel)
{
	Super::LevelUp(CurrentLevelOfIronWorks, MaxLevel);
	MaxLevel = 10;
	
	if (CurrentLevelOfIronWorks == 1)
	{
		IronWorksFlipbookComponent->SetFlipbook(Level1);

	}
	if (CurrentLevelOfIronWorks == 5)
	{
		IronWorksFlipbookComponent->SetFlipbook(Level5);
	}
	if (CurrentLevelOfIronWorks == MaxLevel)
	{
		IronWorksFlipbookComponent->SetFlipbook(Level10);
	}
	if (CurrentLevelOfIronWorks != MaxLevel)
	{
		LevelStatsIncreaseIronWorks(CurrentLevelOfIronWorks);
	}
}

void AIronWorks::DestroyLevel(float& LevelOfIronWorks, float Building_HP)
{
	Super::DestroyLevel(CurrentLevelOfIronWorks, Building_HP);

	if (CurrentLevelOfIronWorks < 10)
	{
		//zmiana meshu

	}
	if (CurrentLevelOfIronWorks < 5)
	{
		//Zmiana meshu 2
	}
	if (CurrentLevelOfIronWorks < 1)
	{
		//zmiana meshu na ten finalny, nie ma nic dalej
	}
}

void AIronWorks::LevelStatsIncreaseIronWorks(float& IronWorksSize)
{

}

void AIronWorks::SettingFlipbookComponent()
{
	IronWorksFlipbookComponent = FindComponentByClass<UPaperFlipbookComponent>();

}
