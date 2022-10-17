// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "myBaseGeometryActor.generated.h"

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

	UPROPERTY(EditAnywhere, Category="Movement")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Frequency = 2.0f;

private:

	FVector InitialLocation;
	void PrintTypes();
	void PrintStringTypes();
	void PrintTransform();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
