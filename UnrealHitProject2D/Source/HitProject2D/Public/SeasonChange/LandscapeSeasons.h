// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LandscapeMaterialInstanceConstant.h"
#include "LandscapeSeasons.generated.h"

/**
 * 
 */
UCLASS()
class HITPROJECT2D_API ULandscapeSeasons : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Season Winter")
	void Winter(bool Condition, );
	UFUNCTION(BlueprintCallable, Category = "Season Winter")
	void Spring(bool Condition, );
	UFUNCTION(BlueprintCallable, Category = "Season Winter")
	void Autumn(bool Condition, );
	UFUNCTION(BlueprintCallable, Category = "Season Winter")
	void Summer(bool Condition, );
protected:

private:


};
