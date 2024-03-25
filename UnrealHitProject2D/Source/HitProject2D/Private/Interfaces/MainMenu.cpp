#include "Interfaces/MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "GameFramework/GameModeBase.h"

void UMainMenu::NativeConstruct()
{
    Super::NativeConstruct();
    if (NewGame)
    {
        NewGame->OnClicked.AddDynamic(this, &UMainMenu::NewGameFunction);
    }

    if (LoadingGame)
    {
        LoadingGame->OnClicked.AddDynamic(this, &UMainMenu::LoadGame);
    }

    if (Setting)
    {
        Setting->OnClicked.AddDynamic(this, &UMainMenu::OpenOptions);
    }

    if (Exit)
    {
        Exit->OnClicked.AddDynamic(this, &UMainMenu::ExitGame);
    }

    PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = true;
        PlayerController->SetInputMode(FInputModeUIOnly());
    }
}

void UMainMenu::NewGameFunction()
{
    UWorld* World = GetWorld();

    PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = false;
        PlayerController->SetInputMode(FInputModeGameOnly());

    }
    UGameplayStatics::OpenLevel(World, TEXT("Main"));
}

void UMainMenu::LoadGame()
{
    //Funkcja wczytywania gry
}

void UMainMenu::OpenOptions()
{
    //Funkcja uruchamiaj?ca opcje
}

void UMainMenu::ExitGame()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}