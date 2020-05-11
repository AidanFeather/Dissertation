// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DissertationCharacter.h"
#include "Engine.h"
#include "Engine/Engine.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" 
#include "Engine/Engine.h"
#include "Desert.generated.h"

/**
 * 
 */
UCLASS()
class DISSERTATION_API ADesert : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

public:

	ADesert();

	UFUNCTION()
		void OnOverlapBegin(class AActor* Overlapped, class AActor* Other);

	UFUNCTION()
		void OnOverlapEnd(class AActor* Overlapped, class AActor* Other);

	float WeaponVariable;

	bool OverlapIsTrue = false;

	
};