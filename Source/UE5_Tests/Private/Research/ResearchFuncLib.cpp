// Fill out your copyright notice in the Description page of Project Settings.


#include "Research/ResearchFuncLib.h"

DEFINE_LOG_CATEGORY_STATIC(LogResearchFuncLib, All, All);

int32 UResearchFuncLib::FibonacciRec(int32 Index)
{
    //check(Index >= 0);

    if (Index < 0)
    {
        UE_LOG(LogResearchFuncLib, Error, TEXT("Incorrect index passed to FibonacciRec: %d"), Index);
    }

    return Index <= 1 ? Index : FibonacciRec(Index - 1) + FibonacciRec(Index - 2);
}