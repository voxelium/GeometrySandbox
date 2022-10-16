// Fill out your copyright notice in the Description page of Project Settings.


#include "myBaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(aLogBaseGeometry, All, All)

// Sets default values
AmyBaseGeometryActor::AmyBaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AmyBaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();
	
	PrintTypes();
	
	// PrintStringTypes();

	
}

void AmyBaseGeometryActor::PrintTypes()
{
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Actor Name: %s"), *GetName());
	UE_LOG(aLogBaseGeometry,Display,TEXT("Weapons num: %d, kills num %i"), WeaponsNum, KillsNum);
	UE_LOG(aLogBaseGeometry,Display,TEXT("Health: %.f"), Health);
	UE_LOG(aLogBaseGeometry,Display,TEXT("Is Dead: %d"), IsDead);
	UE_LOG(aLogBaseGeometry,Display,TEXT("Has Weapon: %d"), static_cast<int>(HasWeapon));
}

void AmyBaseGeometryActor::PrintStringTypes()
{
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Actor Name: %s"), *GetName());

	FString Name = "John Connor";
	UE_LOG(aLogBaseGeometry, Display, TEXT("Name: %s"), *Name);
	
	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is Dead = " + FString(IsDead ? "True" : "False");

	FString Stat = FString::Printf(TEXT(" \n == ALL STAT ==  \n %s \n %s \n %s "), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(aLogBaseGeometry, Warning, TEXT("%s"), *Stat);
	
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, Name, true);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, Stat, true);
	
}


// Called every frame
void AmyBaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

