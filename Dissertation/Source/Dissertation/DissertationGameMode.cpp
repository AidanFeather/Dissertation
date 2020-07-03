// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DissertationGameMode.h"
#include "DissertationHUD.h"
#include "DissertationCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

ADissertationGameMode::ADissertationGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADissertationHUD::StaticClass();


}

void ADissertationGameMode::BeginPlay()
{
	Super::BeginPlay();

	Current(EGamePlayState::EPlaying);

	MyPlayer = Cast<ADissertationCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ADissertationGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyPlayer)
	{
		if (FMath::IsNearlyZero(MyPlayer->GetHealth(), 0.001f))
		{
			Current(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState ADissertationGameMode::GetCurrentState() const
{
	return CState;
}

void ADissertationGameMode::Current(EGamePlayState NT)
{
	CState = NT;
	HandleNewState(CState);
}

void ADissertationGameMode::HandleNewState(EGamePlayState NS) 
{
	switch (NS)
	{
	case EGamePlayState::EPlaying:
	{

	}
	break;

	case EGamePlayState::EGameOver:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;

	default:
	case EGamePlayState::EUnknown:
	{

	}
	break;
	}
}
