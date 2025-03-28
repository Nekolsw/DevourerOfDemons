// Fill out your copyright notice in the Description page of Project Settings.


#include "GE_CalculationGainedEXP.h"
#include "GameplayEffectExtension.h"
#include "HeroAttributeSet.h"


UGE_CalculationGainedEXP::UGE_CalculationGainedEXP()
{
	//The capture DemonSouls NPC provides
	GainedDemonSoulsDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetGainedDemonSoulsAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);

	//The capture EXP that NPC provides
	GainedEXPQiDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetGainedEXPQiAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	GainedEXPSwordsmanshipDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetGainedEXPSwordsmanshipAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	GainedLVLBodyHardeningDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetGainedLVLBodyHardeningAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	
	//The capture current player LVL and EXP
	CurrentEXPQiDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetCurrentEXPQiAttribute(), EGameplayEffectAttributeCaptureSource::Target, true);
	CurrentEXPSwordsmanshipDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetCurrentEXPSwordsmanshipAttribute(), EGameplayEffectAttributeCaptureSource::Target, true);
	CurrentLVLBodyHardeningDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetCurrentLVLBodyHardeningAttribute(), EGameplayEffectAttributeCaptureSource::Target, true);

	//The capture required EXP to level up
	RequiredEXPSwordsmanshipDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetRequiredEXPSwordsmanshipAttribute(), EGameplayEffectAttributeCaptureSource::Target, true);
	RequiredEXPQiDef = FGameplayEffectAttributeCaptureDefinition(UHeroAttributeSet::GetRequiredEXPQiAttribute(), EGameplayEffectAttributeCaptureSource::Target, true);

    //Registering the attribute capture in the system GAS
	RelevantAttributesToCapture.Add(GainedDemonSoulsDef);

    RelevantAttributesToCapture.Add(GainedEXPQiDef);
    RelevantAttributesToCapture.Add(GainedEXPSwordsmanshipDef);
    RelevantAttributesToCapture.Add(GainedLVLBodyHardeningDef);

	RelevantAttributesToCapture.Add(CurrentEXPQiDef);
	RelevantAttributesToCapture.Add(CurrentEXPSwordsmanshipDef);
	RelevantAttributesToCapture.Add(CurrentLVLBodyHardeningDef);

	RelevantAttributesToCapture.Add(RequiredEXPSwordsmanshipDef);
	RelevantAttributesToCapture.Add(RequiredEXPQiDef);
}

void UGE_CalculationGainedEXP::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{

    float GainedEXPQi, GainedEXPSwordsmanship, GainedLVLBodyHardening, GainedDemonSouls;
	float CurrentEXPQi, CurrentEXPSwordsmanship, CurrentLVLBodyHardening;
	float RequiredEXPQi, RequiredEXPSwordsmanship;

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GainedDemonSoulsDef, FAggregatorEvaluateParameters(), GainedDemonSouls);

    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GainedEXPQiDef, FAggregatorEvaluateParameters(), GainedEXPQi);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GainedEXPSwordsmanshipDef, FAggregatorEvaluateParameters(), GainedEXPSwordsmanship);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GainedLVLBodyHardeningDef, FAggregatorEvaluateParameters(), GainedLVLBodyHardening);

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(CurrentEXPQiDef, FAggregatorEvaluateParameters(), CurrentEXPQi);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(CurrentEXPSwordsmanshipDef, FAggregatorEvaluateParameters(), CurrentEXPSwordsmanship);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(CurrentLVLBodyHardeningDef, FAggregatorEvaluateParameters(), CurrentLVLBodyHardening);

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(RequiredEXPQiDef, FAggregatorEvaluateParameters(), RequiredEXPQi);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(RequiredEXPSwordsmanshipDef, FAggregatorEvaluateParameters(), RequiredEXPSwordsmanship);

	FGameplayModifierEvaluatedData DemonSoulsData(UHeroAttributeSet::GetDemonSoulsAttribute(), EGameplayModOp::Additive, GainedDemonSouls);

	FGameplayModifierEvaluatedData LVLBodyHardeningData(UHeroAttributeSet::GetCurrentLVLBodyHardeningAttribute(), EGameplayModOp::Additive, 1.f);
	FGameplayModifierEvaluatedData LVLSwordsmanshipData(UHeroAttributeSet::GetCurrentLVLSwordsmanshipAttribute(), EGameplayModOp::Additive, 1.f);
	FGameplayModifierEvaluatedData LVLQiData(UHeroAttributeSet::GetCurrentLVLQiAttribute(), EGameplayModOp::Additive, 1.f);



	CurrentEXPSwordsmanship += GainedEXPSwordsmanship;
	CurrentEXPQi += GainedEXPQi;

	while (CurrentEXPSwordsmanship >= RequiredEXPSwordsmanship)
	{
		OutExecutionOutput.AddOutputModifier(LVLSwordsmanshipData);
		CurrentEXPSwordsmanship -= RequiredEXPSwordsmanship;
	}

	while (CurrentEXPQi >= RequiredEXPQi)
	{
		OutExecutionOutput.AddOutputModifier(LVLQiData);
		CurrentEXPQi -= RequiredEXPQi;
	}

	while (GainedLVLBodyHardening >= 1.f)
	{

		OutExecutionOutput.AddOutputModifier(LVLBodyHardeningData);
		GainedLVLBodyHardening -= 1.f;
	}

	if (GainedDemonSouls != 0.f)
	{
		OutExecutionOutput.AddOutputModifier(DemonSoulsData);
		GainedDemonSouls = 0;
	}
	FGameplayModifierEvaluatedData EXPQiData(UHeroAttributeSet::GetCurrentEXPQiAttribute(), EGameplayModOp::Override, CurrentEXPQi);
	FGameplayModifierEvaluatedData EXPSwordsmanshipData(UHeroAttributeSet::GetCurrentEXPSwordsmanshipAttribute(), EGameplayModOp::Override, CurrentEXPSwordsmanship);
	OutExecutionOutput.AddOutputModifier(EXPQiData); 
	OutExecutionOutput.AddOutputModifier(EXPSwordsmanshipData);
	
}
