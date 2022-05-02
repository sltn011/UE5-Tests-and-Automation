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

int32 UResearchFuncLib::FibonacciIterative(int32 Index)
{
    if (Index < 0)
    {
        UE_LOG(LogResearchFuncLib, Error, TEXT("Incorrect index passed to FibonacciIterative: %d"), Index);
    }

    int32 PrevPrev = 0;
    int32 Prev = 1;
    int32 Current = -1;
    for (int32 i = 2; i <= Index; ++i)
    {
        Current = Prev + PrevPrev;
        PrevPrev = Prev;
        Prev = Current;
    }

    return Index <= 1 ? Index : Current;
}