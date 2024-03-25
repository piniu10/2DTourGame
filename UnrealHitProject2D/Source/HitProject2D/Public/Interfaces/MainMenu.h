#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"


class UButton;
class AGameModeBase;

UCLASS()
class HITPROJECT2D_API UMainMenu : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;
protected:

    UFUNCTION(BlueprintCallable)
    void NewGameFunction();

    UFUNCTION(BlueprintCallable)
    void LoadGame();

    UFUNCTION(BlueprintCallable)
    void OpenOptions();

    UFUNCTION(BlueprintCallable)
    void ExitGame();
    APlayerController* PlayerController;

private:

    UPROPERTY(meta = (BindWidget))
    UButton* NewGame;

    UPROPERTY(meta = (BindWidget))
    UButton* LoadingGame;

    UPROPERTY(meta = (BindWidget))
    UButton* Setting;

    UPROPERTY(meta = (BindWidget))
    UButton* Exit;
};