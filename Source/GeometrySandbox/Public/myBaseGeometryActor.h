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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void PrintTypes();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
