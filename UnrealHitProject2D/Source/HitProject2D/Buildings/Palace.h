#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "Palace.generated.h"

class UPaperFlipbook;
class UPaperFlipbookComponent;

UCLASS()
class HITPROJECT2D_API APalace : public ABuilding
{
    GENERATED_BODY()

public:
    float VillageLevel;

protected:
    float CurrentLevelOfPalace;
    float BaseDefenceValueofPalace;
    

    virtual void LevelUp(float NewLevel, float MaxLevel) override;
    virtual void DestroyLevel(float LevelOfPalace, float Building_HP) override;
   
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UPaperFlipbook* Level1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UPaperFlipbook* Level2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UPaperFlipbook* Level3;

private:

};
