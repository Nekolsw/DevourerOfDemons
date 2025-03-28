// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroAttributeSet.h"

void UHeroAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetCurrentHealthAttribute()) 
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxHealth());
	}
	
	if (Attribute == GetCurrentEnergyAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxEnergy());
	}
	

	Super::PreAttributeBaseChange(Attribute, NewValue);
}

void UHeroAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetCurrentHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxHealth());
	}

	if (Attribute == GetCurrentEnergyAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxEnergy());
	}

	Super::PreAttributeBaseChange(Attribute, NewValue);

}

