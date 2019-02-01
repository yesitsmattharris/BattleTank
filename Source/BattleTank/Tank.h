// Copyright Matt Harris

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	UPROPERTY(BluePrintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UTankBarrel* Barrel = nullptr; // TODO Remove

	UPROPERTY(BluePrintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BluePrintCallable)
	void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;

	double LastFireTime = 0;

	virtual void BeginPlay() override;
};
