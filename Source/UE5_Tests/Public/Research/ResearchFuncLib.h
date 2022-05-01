// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ResearchFuncLib.generated.h"


UCLASS()
class UE5_TESTS_API UResearchFuncLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "Research | Fibonacci")
	static int32 FibonacciRec(int32 Index);

};
