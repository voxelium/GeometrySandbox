// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "myBaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};


USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category="Movement")
	EMovementType MoveType = EMovementType::Static;

	
};

UCLASS()
class GEOMETRYSANDBOX_API AmyBaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmyBaseGeometryActor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Geometry Data")
	FGeometryData GeometryData;
	
	UPROPERTY(EditAnywhere, Category="Properties")
	int32 WeaponsNum = 4;

	UPROPERTY(EditAnywhere, Category="Properties")
	int32 KillsNum = 7;

	UPROPERTY(EditAnywhere, Category="Properties")
	float Health = 34.874555f;

	UPROPERTY(EditAnywhere, Category="Properties")
	bool IsDead = false;

	UPROPERTY(EditAnywhere, Category="Properties")
	bool HasWeapon = true;

	

private:

	FVector InitialLocation;
	void PrintTypes();
	void PrintStringTypes();
	void PrintTransform();
	void HandleMovement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
