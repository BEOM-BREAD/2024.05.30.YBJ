// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffectManager.h"

#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
AMyEffectManager::AMyEffectManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CreateParticle("DaggerAttack", "/Script/Engine.ParticleSystem'/Game/ParagonKallari/FX/Particles/Kallari/Abilities/DaggerThrow/FX/P_Kallari_DaggerThrow_HitPlayer.P_Kallari_DaggerThrow_HitPlayer'");
}

void AMyEffectManager::CreateParticle(FString name, FString path)
{
	static ConstructorHelpers::FObjectFinder<UParticleSystem> explosion(*path);
	{
		if (explosion.Succeeded())
		{
			for (int i = 0; i < _poolCount; i++)
			{
				UParticleSystem* particle = explosion.Object;
				_table.Add(name, particle);
			}
		}
	}
}

// Called when the game starts or when spawned
void AMyEffectManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyEffectManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyEffectManager::Play(FString name, FVector location, FRotator rotator)
{
	if (_table.Contains(name) == false)
		return;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), _table[name], location, rotator);
}

