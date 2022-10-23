// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "myBaseGeometryActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOncolorChanged, const FLinearColor&, Color, const FString&, Name);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTimerFinished, AActor*);

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	EMovementType MoveType = EMovementType::Static;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Design")
	FLinearColor Color = FLinearColor::Black;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Design")
	float TimerRate = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Design")
	int32 MaxTimerCount = 5;
	
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

	void SetGeometryData (const FGeometryData& Data)
	{
		GeometryData = Data;
	}

	
	UFUNCTION(BlueprintCallable)
	FGeometryData GetGeometryData() const
	{
		return GeometryData;
	};

	UPROPERTY(BlueprintAssignable)
	FOncolorChanged OncolorChanged;
	
	FOnTimerFinished OnTimerFinished;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geometry Data")
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


	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

private:

	FTimerHandle TimerHandle;
	// const int32 MaxTimerCount = 5;
	int32 TimerCount = 0;
	
	FVector InitialLocation;
	void PrintTypes();
	void PrintStringTypes();
	void PrintTransform();
	void HandleMovement();
	void SetColor(const FLinearColor& Color);

	void OnTimerFired();



};
