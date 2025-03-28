// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HeroAttributeSet.generated.h"

// Macro to easily declare attribyte
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) 

UCLASS()
class DEVOUREROFDEMONS_API UHeroAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:


	//Current Health
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UHeroAttributeSet, CurrentHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UHeroAttributeSet, MaxHealth)

	//Current Energy
	UPROPERTY(BlueprintReadOnly, Category = "Energy")
	FGameplayAttributeData CurrentEnergy;
	ATTRIBUTE_ACCESSORS(UHeroAttributeSet, CurrentEnergy)

	UPROPERTY(BlueprintReadOnly, Category = "Energy")
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(UHeroAttributeSet, MaxEnergy)

	//Current Pilule
	UPROPERTY(BlueprintReadOnly, Category = "Energy")
	FGameplayAttributeData CurrentPilule;
	ATTRIBUTE_ACCESSORS(UHeroAttributeSet, CurrentPilule)

	UPROPERTY(BlueprintReadOnly, Category = "Energy")
	FGameplayAttributeData MaxPilule;
	ATTRIBUTE_ACCESSORS(UHeroAttributeSet, MaxPilule)
	
	//Current DemonSouls
	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float DemonSouls;

	//Current Level Qi
	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float CurrentLVLQi;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float MaxLVLQi;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float CurrentEXPQi;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float RequiredEXPQi;

	//Current Level Swordsmanship
	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float CurrentLVLSwordsmanship;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float MaxLVLSwordsmanship;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float CurrentEXPSwordsmanship;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float RequiredEXPSwordsmanship;

	//Current Level BodyHardening

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float CurrentLVLBodyHardening;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float MaxLVLBodyHardening;

	//Gained DemonSouls
	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float GainedDemonSouls;

	//EXP and LVL gained from mobs
	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float GainedEXPQi;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float GainedEXPSwordsmanship;

	UPROPERTY(BlueprintReadOnly, Category = "Level", meta = (AllowPrivateAccess = "true"))
	float GainedLVLBodyHardening;


	static FGameplayAttribute GetGainedDemonSoulsAttribute()
	{
		static FProperty* GainedDemonSoulsProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, GainedDemonSouls));
		return FGameplayAttribute(GainedDemonSoulsProp);
	}

	static FGameplayAttribute GetGainedEXPQiAttribute()
	{
		static FProperty* GainedEXPQiProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, GainedEXPQi));
		return FGameplayAttribute(GainedEXPQiProp);
	}

	static FGameplayAttribute GetGainedEXPSwordsmanshipAttribute()
	{
		static FProperty* GainedEXPSwordsmanshipProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, GainedEXPSwordsmanship));
		return FGameplayAttribute(GainedEXPSwordsmanshipProp);
	}

	static FGameplayAttribute GetGainedLVLBodyHardeningAttribute()
	{
		static FProperty* GainedLVLBodyHardeningProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, GainedLVLBodyHardening));
		return FGameplayAttribute(GainedLVLBodyHardeningProp);
	}

	static FGameplayAttribute GetDemonSoulsAttribute()
	{
		static FProperty* DemonSoulsProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, DemonSouls));
		return FGameplayAttribute(DemonSoulsProp);
	}

	static FGameplayAttribute GetCurrentEXPQiAttribute()
	{
		static FProperty* CurrentEXPQiProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, CurrentEXPQi));
		return FGameplayAttribute(CurrentEXPQiProp);
	}

	static FGameplayAttribute GetRequiredEXPQiAttribute()
	{
		static FProperty* RequiredEXPQiProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, RequiredEXPQi));
		return FGameplayAttribute(RequiredEXPQiProp);
	}

	static FGameplayAttribute GetCurrentEXPSwordsmanshipAttribute()
	{
		static FProperty* CurrentEXPSwordsmanshipProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, CurrentEXPSwordsmanship));
		return FGameplayAttribute(CurrentEXPSwordsmanshipProp);
	}

	static FGameplayAttribute GetRequiredEXPSwordsmanshipAttribute()
	{
		static FProperty* RequiredEXPSwordsmanshipProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, RequiredEXPSwordsmanship));
		return FGameplayAttribute(RequiredEXPSwordsmanshipProp);
	}

	static FGameplayAttribute GetCurrentLVLQiAttribute()
	{
		static FProperty* CurrentLVLQiProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, CurrentLVLQi));
		return FGameplayAttribute(CurrentLVLQiProp);
	}

	static FGameplayAttribute GetCurrentLVLSwordsmanshipAttribute()
	{
		static FProperty* CurrentLVLSwordsmanshipProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, CurrentLVLSwordsmanship));
		return FGameplayAttribute(CurrentLVLSwordsmanshipProp);
	}

	static FGameplayAttribute GetCurrentLVLBodyHardeningAttribute()
	{
		static FProperty* CurrentLVLBodyHardeningProp = FindFieldChecked<FProperty>(UHeroAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UHeroAttributeSet, CurrentLVLBodyHardening));
		return FGameplayAttribute(CurrentLVLBodyHardeningProp);
	}

protected:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
};
