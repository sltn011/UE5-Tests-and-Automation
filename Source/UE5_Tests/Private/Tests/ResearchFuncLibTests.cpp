// Fill out your copyright notice in the Description page of Project Settings.

#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "Tests/ResearchFuncLibTests.h"
#include "Misc/AutomationTest.h"

#include "Research/ResearchFuncLib.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FResearchFibonacciRecTest, "UE5_Tests.Research Func Lib.Fibonacci.Recursive",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FResearchFibonacciRecTest::RunTest(const FString &Parameters)
{
    AddInfo("ResearchFuncLib::FibonacciRec Testing");

    struct TestPayload
    {
        int32 TestValue;
        int32 ExpectedValue;
    };

    const TArray<TestPayload> TestsData = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, 2},
        {5, 5},
        {10, 55}
    };

    for (const auto &Payload : TestsData)
    {
        FString Description = FString::Printf(TEXT("Fibonacci(%d)"), Payload.TestValue);
        TestEqual(Description, UResearchFuncLib::FibonacciRec(Payload.TestValue), Payload.ExpectedValue);
    }

    return true;
}

#endif
