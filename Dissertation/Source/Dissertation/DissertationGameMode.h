// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "DissertationGameMode.generated.h"

class ADissertationCharacter;

UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class ADissertationGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADissertationGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ADissertationCharacter* MyPlayer;

	UFUNCTION(BlueprintPure, Category = "Health")
		EGamePlayState GetCurrentState() const;

	void Current(EGamePlayState New);

private:

	EGamePlayState CState;

	void HandleNewState(EGamePlayState NS);
};



