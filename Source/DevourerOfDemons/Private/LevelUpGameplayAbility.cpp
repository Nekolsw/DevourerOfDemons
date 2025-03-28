// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelUpGameplayAbility.h"
#include "HeroAttributeSet.h"



void ULevelUpGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	if (!ActorInfo || !ActorInfo->AbilitySystemComponent.Get())
	{
		return;
	}

	UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();

	const UHeroAttributeSet* HeroAttributes = ASC->GetSet<UHeroAttributeSet>();
	if (!HeroAttributes)
	{
		return;
	}

	
	ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentEXPSwordsmanshipAttribute(), EGameplayModOp::Additive, ReceivedEXPSwordsmanship);
	ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentEXPQiAttribute(), EGameplayModOp::Additive, ReceivedEXPQi);

	float EXPSwordsmanship = ASC->GetNumericAttribute(HeroAttributes->GetCurrentEXPSwordsmanshipAttribute());
	float EXPQi = ASC->GetNumericAttribute(HeroAttributes->GetCurrentEXPQiAttribute());
	const float LVLBodyHardening = ASC->GetNumericAttribute(HeroAttributes->GetCurrentLVLBodyHardeningAttribute());

	const float RequiredEXPSwordsmanship = ASC->GetNumericAttribute(HeroAttributes->GetRequiredEXPSwordsmanshipAttribute());
	const float RequiredEXPQi = ASC->GetNumericAttribute(HeroAttributes->GetRequiredEXPQiAttribute());

	while (EXPSwordsmanship >= RequiredEXPSwordsmanship)
	{
		ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentEXPSwordsmanshipAttribute(), EGameplayModOp::Additive, -RequiredEXPSwordsmanship);
		ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentLVLSwordsmanshipAttribute(), EGameplayModOp::Additive, 1.f);
		EXPSwordsmanship = ASC->GetNumericAttribute(HeroAttributes->GetCurrentEXPSwordsmanshipAttribute());
	}

	while (EXPQi >= RequiredEXPQi)
	{
		ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentEXPQiAttribute(), EGameplayModOp::Additive, -RequiredEXPQi);
		ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentLVLQiAttribute(), EGameplayModOp::Additive, 1.f);
		EXPQi = ASC->GetNumericAttribute(HeroAttributes->GetCurrentEXPQiAttribute());
	}

	while (ReceivedLVLBodyHardening >= 1.f)
	{
		ASC->ApplyModToAttribute(UHeroAttributeSet::GetCurrentLVLBodyHardeningAttribute(), EGameplayModOp::Additive, 1.f);
		--ReceivedLVLBodyHardening;
	}

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

