// Fill out your copyright notice in the Description page of Project Settings.


#include "CostGameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "HeroAttributeSet.h"

UCostGameplayAbility::UCostGameplayAbility()
{
	
}

void UCostGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UCostGameplayAbility::ApplyCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) const
{
if (!ActorInfo || !ActorInfo->AbilitySystemComponent.Get())
{
	return;
}

UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();

const UHeroAttributeSet* Attributes = ASC->GetSet<UHeroAttributeSet>();
if (!Attributes)
{
	return;
}

// Уменьшаем запас энергии
ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentEnergyAttribute(), EGameplayModOp::Additive, -CostAbility);

}

bool UCostGameplayAbility::CheckCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get(); 
	if (ASC)
	{
		const UHeroAttributeSet* HeroAttributes = ASC->GetSet<UHeroAttributeSet>();
		const float CurrentEnergy = ASC->GetNumericAttribute(HeroAttributes->GetCurrentEnergyAttribute());
		// проверяем, достаточно ли энергии для активации способности 
		if (CurrentEnergy >= CostAbility)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

