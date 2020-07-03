// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DissertationHUD.generated.h"

UCLASS()
class ADissertationHUD : public AHUD
{
	GENERATED_BODY()

public:
	ADissertationHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;



private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;


	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget* Current;

};

