// Fill out your copyright notice in the Description page of Project Settings.


#include "myBaseGeometryActor.h"

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
	
	//PrintTypes();

	FString Name = "John Connor";
	UE_LOG(aLogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	int WeaponsNum = 4;
	float Health = 34.874555f;
	bool IsDead = false;
	
	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is Dead = " + FString(IsDead ? "True" : "False");

	FString Stat = FString::Printf(TEXT(" \n == ALL STAT ==  \n %s \n %s \n %s "), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(aLogBaseGeometry, Warning, TEXT("Stat"));

	
}

void AmyBaseGeometryActor::PrintTypes()
{
	UE_LOG(aLogBaseGeometry,Display,TEXT("Привет. Как дела?"));
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Привет. Как дела?"));
	UE_LOG(aLogBaseGeometry,Error,TEXT("Привет. Как дела?"));

	int WeaponsNum = 4;
	int KillsNum = 7;
	float Health = 34.874555f;
	bool IsDead = false;
	bool HasWeapon = true;

	UE_LOG(aLogBaseGeometry,Warning,TEXT("Weapons num: %d, kills num %i"), WeaponsNum, KillsNum);
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Health: %.f"), Health);
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Health: %.2f"), Health);
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Is Dead: %i"), IsDead);
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Is Dead: %d"), IsDead);
	UE_LOG(aLogBaseGeometry,Warning,TEXT("Has Weapon: %d"), static_cast<int>(HasWeapon));
}

// Called every frame
void AmyBaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

