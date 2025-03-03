// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "Calc_LossEnergy.generated.h"

/**
 * 
 */
UCLASS()
class DEVOUREROFDEMONS_API UCalc_LossEnergy : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UCalc_LossEnergy();

	float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;



	
};
