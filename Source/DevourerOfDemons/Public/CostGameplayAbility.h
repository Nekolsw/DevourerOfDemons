// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CostGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class DEVOUREROFDEMONS_API UCostGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	float Cost;
};
