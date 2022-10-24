// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxPlayerController.h"

#include "SandboxPawn.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogPLayerController, All, All);

void ASandboxPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(InputComponent)
	{
		InputComponent->BindAction("ChangePawn", IE_Pressed, this, &ASandboxPlayerController::ChangePawn);
	
	}
	
}

void ASandboxPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASandboxPawn::StaticClass(), Pawns);

	UE_LOG(LogPlayerController, Error, TEXT("There are %i Pawns on the scene"), Pawns.Num());
}

void ASandboxPlayerController::ChangePawn()
{
	if (Pawns.Num() <=1) return;

	ASandboxPawn* CurrentPawn = Cast<ASandboxPawn>(Pawns[CurrentPawnIndex]);
	CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();

	if (!CurrentPawn) return;

	UE_LOG(LogPlayerController, Display, TEXT("Change Pawn"));
	Possess(CurrentPawn);
	
}
