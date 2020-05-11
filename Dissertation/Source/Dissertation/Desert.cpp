// Fill out your copyright notice in the Description page of Project Settings.


#include "Desert.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"



ADesert::ADesert()
{
	OnActorBeginOverlap.AddDynamic(this, &ADesert::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ADesert::OnOverlapEnd);
}

ADissertationCharacter* Character;

void ADesert::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(),FColor::Blue, true, 999, 0, 5);

	Character = Cast<ADissertationCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));;
	

}

void ADesert::OnOverlapBegin(class AActor* Overlapped, class AActor* Other)
{
	if (Other && (Other != this))
	{
		if (GEngine) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *Overlapped->GetName()));
			OverlapIsTrue = true;
			Character->Desert();
		}
	}
}

void ADesert::OnOverlapEnd(class AActor* Overlapped, class AActor* Other)
{
	if (Other && (Other != this))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *Other->GetName()));
			OverlapIsTrue = false;
			Character->Neutral();
		}
	}

}

