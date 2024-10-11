// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GMCAbilityTaskBase.h"
#include "SetTargetDataStruct.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUGMCAbilityTaskTargetDataStructAsyncActionPin, FInstancedStruct, Target);

USTRUCT(BlueprintType)
struct FGMCAbilityTaskTargetDataStruct : public FGMCAbilityTaskData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "GMCAbilitySystem")
	FInstancedStruct Target{nullptr};
};

/**
 * 
 */
UCLASS()
class GMCABILITYSYSTEM_API UGMCAbilityTask_SetTargetDataStruct : public UGMCAbilityTaskBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FUGMCAbilityTaskTargetDataStructAsyncActionPin	Completed;
		
	UPROPERTY(BlueprintReadWrite, Category = "GMCAbilitySystem")
	FInstancedStruct Target{nullptr};
		
	virtual void ProgressTask(FInstancedStruct& TaskData) override;
	virtual void ClientProgressTask() override;
	 
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"), DisplayName="Set Target Data (Instanced Struct)",Category = "GMCAbilitySystem/Tasks")
	static UGMCAbilityTask_SetTargetDataStruct* SetTargetDataStruct(UGMCAbility* OwningAbility, const FInstancedStruct& InstancedStruct);
	 
	//Overriding BP async action base
	virtual void Activate() override;
	
};
