// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "LevelUpGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class DEVOUREROFDEMONS_API ULevelUpGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, Category = "EXP")
	float ReceivedEXPSwordsmanship;

	UPROPERTY(EditAnywhere, Category = "EXP")
	float  ReceivedEXPQi;

	UPROPERTY(EditAnywhere, Category = "LVL")
	float  ReceivedLVLBodyHardening;
;

	void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
