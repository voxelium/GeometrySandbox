// Fill out your copyright notice in the Description page of Project Settings.


#include "myBaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(aLogBaseGeometry, All, All)

// Sets default values
AmyBaseGeometryActor::AmyBaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);

}

// Called when the game starts or when spawned
void AmyBaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	//Вывожу в Log данные
	//PrintTypes();

	//Вывожу данные в Log и на экран
	// PrintStringTypes();

	//Вывожу в Log данные о трасформации
	PrintTransform();

	//Создаю инстанс материала и присваиваю его к объекту
	SetColor(GeometryData.Color);

	//Создаю таймер для смены материала
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AmyBaseGeometryActor::OnTimerFired, GeometryData.TimerRate, true);
	
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

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, Name, true);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, Stat, true);

	}
	
	
}

void AmyBaseGeometryActor::PrintTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();
	
	UE_LOG(aLogBaseGeometry, Warning, TEXT("Actor Name: %s"), *GetName());
	UE_LOG(aLogBaseGeometry, Warning, TEXT("Transform: %s"), *Transform.ToString());
	UE_LOG(aLogBaseGeometry, Warning, TEXT("Location: %s"), *Location.ToString());
	UE_LOG(aLogBaseGeometry, Warning, TEXT("Rotation: %s"), *Rotation.ToString());
	UE_LOG(aLogBaseGeometry, Warning, TEXT("Scale: %s"), *Scale.ToString());
	
	UE_LOG(aLogBaseGeometry, Error, TEXT("Human Transform: %s"), *Transform.ToHumanReadableString());
}

void AmyBaseGeometryActor::HandleMovement()
{
	switch (GeometryData.MoveType)
	{
	case EMovementType::Sin:
		{
			FVector CurrentLocation = GetActorLocation();

			if (GetWorld())
			{
				float Time = GetWorld()->GetTimeSeconds();
				CurrentLocation.Z = InitialLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * Time);
	
				SetActorLocation(CurrentLocation);
			}
			
		}
		break;

	case EMovementType::Static: break;
	default: break;
	}
}

void AmyBaseGeometryActor::SetColor(const FLinearColor& Color)
{
	if(!BaseMesh) return;
	UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynMaterial)
	{
		DynMaterial->SetVectorParameterValue("Color", Color);
	}
}

void AmyBaseGeometryActor::OnTimerFired()
{
	if(++TimerCount <= GeometryData.MaxTimerCount)
	{
		const FLinearColor NewColor = FLinearColor::MakeRandomColor();
		SetColor(NewColor);
		OncolorChanged.Broadcast(NewColor, GetName());
	}

	else
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		OnTimerFinished.Broadcast(this);
	}
	
}


// Called every frame
void AmyBaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HandleMovement();
	

}

