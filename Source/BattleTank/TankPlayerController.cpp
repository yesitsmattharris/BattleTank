// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* const ATankPlayerController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}


