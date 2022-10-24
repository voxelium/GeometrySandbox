// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxPawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogSandboxPawn, All,All)

// Sets default values
ASandboxPawn::ASandboxPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");

	//Устанавливает SceneComponent корневым компоненот, чтобы потом было лего аттачить к нему остальные компонены
	//при помощи функции "GetRootComponent"
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	// компонет можно аттачить к любому компоненту сцены актора, не обязательно к RootComponent
	StaticMeshComponent->SetupAttachment(GetRootComponent());
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	// компонет можно аттачить к любому компоненту сцены актора, не обязательно к RootComponent
	CameraComponent->SetupAttachment(GetRootComponent());
	
}


// Called when the game starts or when spawned
void ASandboxPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASandboxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//проверяет вектор велосити на Ноль
	if(!VelocityVector.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + (Velocity * DeltaTime * VelocityVector);
		SetActorLocation(NewLocation);
		VelocityVector = FVector::ZeroVector;
	}
}

// Called to bind functionality to input
void ASandboxPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &ASandboxPawn::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &ASandboxPawn::MoveRight);
	
	}
	

}

void ASandboxPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(!NewController) return;
	UE_LOG(LogSandboxPawn, Display, TEXT("%s Possessed By %s"), *GetName(), *NewController->GetName());
}

void ASandboxPawn::UnPossessed()
{
	Super::UnPossessed();
	
	UE_LOG(LogSandboxPawn, Display, TEXT("%s UN Possessed"), *GetName());
}

void ASandboxPawn::MoveForward(float Amount)
{
	// UE_LOG(LogSandboxPawn, Display, TEXT("Move Forward: %f"), Amount);
	VelocityVector.X = Amount;
	
}

void ASandboxPawn::MoveRight(float Amount)
{
	// UE_LOG(LogSandboxPawn, Display, TEXT("Move Right: %f"), Amount);
	VelocityVector.Y = Amount;
}


