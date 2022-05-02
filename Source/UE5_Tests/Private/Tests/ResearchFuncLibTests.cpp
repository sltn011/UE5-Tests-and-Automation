// Fill out your copyright notice in the Description page of Project Settings.

#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "Tests/ResearchFuncLibTests.h"
#include "Misc/AutomationTest.h"

#include "Research/ResearchFuncLib.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FResearchFibonacciRecTest, "UE5_Tests.ResearchFuncLib.Fibonacci.Recursive",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FResearchFibonacciRecErrors, "UE5_Tests.ResearchFuncLib.Fibonacci.RecursiveErrors",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::NegativeFilter | EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FResearchFibonacciRecStress, "UE5_Tests.ResearchFuncLib.Fibonacci.RecursiveStress",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::StressFilter | EAutomationTestFlags::LowPriority);



IMPLEMENT_SIMPLE_AUTOMATION_TEST(FResearchFibonacciIterTest, "UE5_Tests.ResearchFuncLib.Fibonacci.Iterative",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FResearchFibonacciIterErrors, "UE5_Tests.ResearchFuncLib.Fibonacci.IterativeErrors",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::NegativeFilter | EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FResearchFibonacciIterStress, "UE5_Tests.ResearchFuncLib.Fibonacci.IterativeStress",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::StressFilter | EAutomationTestFlags::LowPriority);



bool FResearchFibonacciRecTest::RunTest(const FString &Parameters)
{
    AddInfo("ResearchFuncLib::FibonacciRec Testing");

    struct TestPayload
    {
        int32 TestValue;
        int32 ExpectedValue;
    };

    const TArray<TestPayload> TestsData = 
    {
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

bool FResearchFibonacciRecErrors::RunTest(const FString &Parameters)
{
    AddInfo("ResearchFuncLib::FibonacciRec Testing with Errors");

    AddExpectedError("Incorrect index passed to FibonacciRec", EAutomationExpectedErrorFlags::Contains, 3);
    UResearchFuncLib::FibonacciRec(-1);
    UResearchFuncLib::FibonacciRec(-100);
    UResearchFuncLib::FibonacciRec(-10000);

    return true;
}

bool FResearchFibonacciRecStress::RunTest(const FString &Parameters)
{
    AddInfo("ResearchFuncLib::FibonacciRec Stress-Testing");

    for (int32 i = 2; i < 40; ++i)
    {
        TestTrueExpr(UResearchFuncLib::FibonacciRec(i) == 
                     UResearchFuncLib::FibonacciRec(i - 1) + UResearchFuncLib::FibonacciRec(i - 2));
    }

    return true;
}

bool FResearchFibonacciIterTest::RunTest(const FString &Parameters)
{
    AddInfo("ResearchFuncLib::FibonacciIterative Testing");

    struct TestPayload
    {
        int32 TestValue;
        int32 ExpectedValue;
    };

    const TArray<TestPayload> TestsData = 
    {
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
        TestEqual(Description, UResearchFuncLib::FibonacciIterative(Payload.TestValue), Payload.ExpectedValue);
    }

    return true;
}

bool FResearchFibonacciIterErrors::RunTest(const FString &Parameters)
{
    AddInfo("ResearchFuncLib::FibonacciIterative Testing with Errors");

    AddExpectedError("Incorrect index passed to FibonacciIterative", EAutomationExpectedErrorFlags::Contains, 3);
    UResearchFuncLib::FibonacciIterative(-1);
    UResearchFuncLib::FibonacciIterative(-100);
    UResearchFuncLib::FibonacciIterative(-10000);

    return true;
}

bool FResearchFibonacciIterStress::RunTest(const FString &Parameters)
{
    AddInfo("ResearchFuncLib::FibonacciIterative Stress-Testing");

    int32 PrevPrev = UResearchFuncLib::FibonacciIterative(0);
    int32 Prev     = UResearchFuncLib::FibonacciIterative(1);
    for (int32 i = 2; i < 40; ++i)
    {
        int32 Current = UResearchFuncLib::FibonacciIterative(i);
        TestTrueExpr(Current == Prev + PrevPrev);
        PrevPrev = Prev;
        Prev = Current;
    }

    return true;
}

#endif
