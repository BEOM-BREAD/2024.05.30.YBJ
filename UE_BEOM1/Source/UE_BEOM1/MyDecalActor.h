// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "MyDecalActor.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_OneParam(FieldAttack, FVector);
UCLASS()
class UE_BEOM1_API AMyDecalActor : public ADecalActor
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime);

	FieldAttack _fieldAttackDelegate;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Decal, meta = (AllowPrivateAccess = "true"))
	FVector2D _minSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Decal, meta = (AllowPrivateAccess = "true"))
	FVector2D _maxSize;
};
