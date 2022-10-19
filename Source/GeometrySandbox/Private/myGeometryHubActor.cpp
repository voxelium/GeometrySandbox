// Fill out your copyright notice in the Description page of Project Settings.


#include "myGeometryHubActor.h"
#include "Engine/World.h"

// Sets default values
AmyGeometryHubActor::AmyGeometryHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AmyGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();
	
	DoActorSpawn1();

	//Спаун с отложенным BeginPlay
	DoActorSpawn2();

	//Спаун с предварительной настройкой данных для акторов в Editor
	DoActorSpawn3();
	
}

// Called every frame
void AmyGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AmyGeometryHubActor::DoActorSpawn1()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (int32 i=0; i<10; ++i)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0,100.0f * i, 0.0f));
			AmyBaseGeometryActor* Geometry = World->SpawnActor<AmyBaseGeometryActor>(GeometryClass, GeometryTransform);

			if (Geometry)
			{
				FGeometryData Data;
				Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
				Geometry->SetGeometryData(Data);	
			}
			
		}
	
	}
}

void AmyGeometryHubActor::DoActorSpawn2()
	{
		UWorld* World = GetWorld();
		if (World)
		{
			//вариант спауна актора без функции BeginPlay
			for (int32 i=0; i<10; ++i)
			{
				const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f,100.0f * i, 200.0f));
				AmyBaseGeometryActor* Geometry = World->SpawnActorDeferred<AmyBaseGeometryActor>(GeometryClass, GeometryTransform);

				if (Geometry)
				{
					FGeometryData Data;
				
					Data.Color = FLinearColor::MakeRandomColor();
					Geometry->SetGeometryData(Data);

					// теперь вызывается функция BeginPlay при помощи FinishSpawning
					Geometry->FinishSpawning(GeometryTransform);
				}
			
			}
		
		}
	}

void AmyGeometryHubActor::DoActorSpawn3()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (const FGeometryPayload Payload: GeometryPayloads)
		{
			AmyBaseGeometryActor* Geometry = World->SpawnActorDeferred<AmyBaseGeometryActor>(Payload.GeometryClass, Payload.InitialTransform);

			if (Geometry)
			{
				Geometry->SetGeometryData(Payload.Data);
				Geometry->FinishSpawning(Payload.InitialTransform);
				
			}
		}
	}
}

