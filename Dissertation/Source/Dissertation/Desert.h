// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/Engine.h"
#include "Engine/TriggerBox.h"
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

};