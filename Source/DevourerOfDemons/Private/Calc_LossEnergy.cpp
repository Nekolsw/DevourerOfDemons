// Fill out your copyright notice in the Description page of Project Settings.


#include "Calc_LossEnergy.h"
#include "HeroAttributeSet.h"

#include "CostGameplayAbility.h"



float UCalc_LossEnergy::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	
	const UCostGameplayAbility* Ability = Cast<UCostGameplayAbility>(Spec.GetContext().GetAbility());

	if (!Ability) 
	{
		return -2.f;
	}
	return Ability->Cost;
	
}
