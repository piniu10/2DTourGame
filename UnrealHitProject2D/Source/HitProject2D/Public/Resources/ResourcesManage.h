// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourcesManage.generated.h"

/**
 * 
 */
UCLASS()
class HITPROJECT2D_API UResourcesManage : public UObject
{
	GENERATED_BODY()
	
public:
	void WoodChangingAfterTour(float& AmountOfWood);
	void StoneChangingAfterTour(float& AmountOfStone);
	void MetalChangingAfterTour(float& AmountOfMetal);

protected:

private:

};
