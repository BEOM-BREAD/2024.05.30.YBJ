// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyMonster.generated.h"

/**
 * 
 */
UCLASS()
class UE_BEOM1_API AMyMonster : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	AMyMonster();

	virtual void BeginPlay() override;

	UFUNCTION()
	void Attack_AI();
	
};
