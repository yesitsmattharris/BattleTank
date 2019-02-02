// Copyright Matt Harris

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensureAlways(PlayerTank && ControlledTank)) { return; }
	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensureAlways(AimingComponent)) { return; }
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	AimingComponent->Fire();
}