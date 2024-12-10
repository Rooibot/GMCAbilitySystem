// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GMCAbilityTaskData.generated.h"

UENUM()
enum EGMCAbilityTaskDataType : uint8
{
	Empty_Task,
	Heartbeat_Task,
	Progress_Task
};


USTRUCT()
struct GMCABILITYSYSTEM_API FGMCAbilityTaskData
{
	GENERATED_BODY()
	// Ability this Task is running under
	UPROPERTY()
	int AbilityID{-1};

	// Task to continue ability execution on
	UPROPERTY()
	int TaskID{-1};

	UPROPERTY()
	TEnumAsByte<EGMCAbilityTaskDataType> TaskType{EGMCAbilityTaskDataType::Empty_Task};
	
	bool operator==(const FGMCAbilityTaskData& Other) const {return AbilityID == Other.AbilityID && TaskID == Other.TaskID && TaskType == Other.TaskType;};
	bool operator!=(const FGMCAbilityTaskData& Other) const {return AbilityID != Other.AbilityID || TaskID != Other.TaskID || TaskType != Other.TaskType;};
};
