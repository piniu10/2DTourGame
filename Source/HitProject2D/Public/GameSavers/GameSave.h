// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameSave.generated.h"

/**
 * 
 */
USaveGame* GameSave;

UCLASS()
class HITPROJECT2D_API UGameSave : public USaveGame
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "SaveGame")
    static bool SaveGame(USaveGame* SaveGameData);

    UFUNCTION(BlueprintCallable, Category = "SaveGame")
    void LoadGame();

    UFUNCTION(BlueprintCallable, Category = "SaveGame")
    static void AutoSaveGame(USaveGame* SaveGameData);
};
