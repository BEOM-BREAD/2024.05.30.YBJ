// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDecalActor.h"
#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"

void AMyDecalActor::BeginPlay()
{
	Super::BeginPlay();

	// TODO :
	// size �ּ�
	GetDecal()->DecalSize.Z = _minSize.X;
	GetDecal()->DecalSize.Y = _minSize.Y;
}

void AMyDecalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// TODO :
	// ���� �ø��ٰ�  �ִ����� �����ϸ�
	// �̺�Ʈ
	if (GetDecal()->DecalSize.Z = _maxSize.X)
	{
		_fieldAttackDelegate.Execute(GetActorLocation());
		GetDecal()->DecalSize.Z = _minSize.X;
		GetDecal()->DecalSize.Y = _minSize.Y;

		return;
	}


	// size ���� �ø���
	GetDecal()->DecalSize.Z = DeltaTime;
	GetDecal()->DecalSize.Y = DeltaTime;
}