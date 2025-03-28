// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GE_CalculationGainedEXP.generated.h"

/**
 * 
 */
UCLASS()
class DEVOUREROFDEMONS_API UGE_CalculationGainedEXP : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UGE_CalculationGainedEXP();
	//The EXP that NPC provides 
	FGameplayEffectAttributeCaptureDefinition GainedEXPQiDef, GainedEXPSwordsmanshipDef, GainedLVLBodyHardeningDef, GainedDemonSoulsDef;

	//Ñurrent player LVL and EXP
	FGameplayEffectAttributeCaptureDefinition CurrentEXPQiDef, CurrentEXPSwordsmanshipDef, CurrentLVLBodyHardeningDef;

	//Required EXP to level up
	FGameplayEffectAttributeCaptureDefinition RequiredEXPQiDef, RequiredEXPSwordsmanshipDef;

	void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
