// Fill out your copyright notice in the Description page of Project Settings.



#include "Building.h"

class UPaperFlipBook;

// Sets default values
ABuilding::ABuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABuilding::LevelUp(float& NewLevel, float MaxLevel)
{
	if (NewLevel != MaxLevel&& NewLevel<MaxLevel)
	{
		NewLevel++;
	}
	else
	{
		//Powiadomienie, ¿e panie nie mo¿emy bardziej rozwin¹æ budynku
	}
}

void ABuilding::DestroyLevel(float& LevelOfBuilding, float Building_HP)
{

	if (LevelOfBuilding > 0 && Building_HP == 0.0f)
	{
		LevelOfBuilding --;
	}
}



// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

