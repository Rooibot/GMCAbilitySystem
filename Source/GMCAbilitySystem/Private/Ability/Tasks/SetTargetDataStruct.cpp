// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/Tasks/SetTargetDataStruct.h"

UGMCAbilityTask_SetTargetDataStruct* UGMCAbilityTask_SetTargetDataStruct::SetTargetDataStruct(
	UGMCAbility* OwningAbility, const FInstancedStruct& Target)
{
	UGMCAbilityTask_SetTargetDataStruct* NewTask = NewAbilityTask<UGMCAbilityTask_SetTargetDataStruct>(OwningAbility);
	NewTask->Ability = OwningAbility;
	NewTask->Target = Target;
	return NewTask;
}

void UGMCAbilityTask_SetTargetDataStruct::ProgressTask(FInstancedStruct& TaskData)
{
	Super::ProgressTask(TaskData);
	const FGMCAbilityTaskTargetDataStruct Data = TaskData.Get<FGMCAbilityTaskTargetDataStruct>();

	Completed.Broadcast(Data.Target);
	EndTask();
	
}

void UGMCAbilityTask_SetTargetDataStruct::ClientProgressTask()
{
	FGMCAbilityTaskTargetDataStruct TaskData;
	TaskData.TaskType = EGMCAbilityTaskDataType::Progress_Task;
	TaskData.AbilityID = Ability->GetAbilityID();
	TaskData.TaskID = TaskID;
	TaskData.Target = Target;
	
	const FInstancedStruct TaskDataInstance = FInstancedStruct::Make(TaskData);
	Ability->OwnerAbilityComponent->QueueTaskData(TaskDataInstance);
}

void UGMCAbilityTask_SetTargetDataStruct::Activate()
{
	Super::Activate();

	if (AbilitySystemComponent->GetNetMode() != NM_DedicatedServer)
	{
		ClientProgressTask();
	}
}

