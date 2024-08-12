#include "MyPawn1.h"
#include "MyPawn1.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn1.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

// Sets default values
AMyPawn1::AMyPawn1()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_sm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_moveMent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	RootComponent = _sm;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT(" / Script / Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (mesh.Succeeded())
	{
		_sm->SetStaticMesh(mesh.Object);
	}


}

// Called when the game starts or when spawned
void AMyPawn1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 대리자 : 함수 포인터, 함수 객체 -> CallAble, 콜백함수
	//PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn1::UpDown);
	//PlayerInputComponent->BindAxis(TEXT("RightLeft"), this, &AMyPawn1::RightLeft);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPawn1::Move);

		// Looking
		EnhancedInputComponent->BindAction(_LookAction, ETriggerEvent::Triggered, this, &AMyPawn1::Look);
	}
}

void AMyPawn1::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMyPawn1::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
}

void AMyPawn1::UpDown(float value)
{
	if (abs(value) >= 0.01)
	{
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, value);
	}
}

void AMyPawn1::RightLeft(float value)
{
	if (abs(value) >= 0.01)
	{
		FVector rightleft = GetActorRightVector();
		AddMovementInput(rightleft, value);
	}
}

