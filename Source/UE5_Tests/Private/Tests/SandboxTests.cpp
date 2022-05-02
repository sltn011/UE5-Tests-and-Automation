// Fill out your copyright notice in the Description page of Project Settings.

#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "Tests/SandboxTests.h"
#include "CoreMinimal.h"

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxIntTest, TEXT("UE5_Tests.Math.MaxInt"),
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FMathMaxIntTest::RunTest(FString const &Parameters)
{
    AddInfo("FMath::Max<int32> Testing");

    struct TestPayload
    {
        TInterval<int32> TestValues;
        int32 ExpectedValue;
    };

    const TArray<TestPayload> TestData =
    {
        {{ +10, +100 }, +100 },
        {{ +10,  +10 },  +10 },
        {{ -10, -100 },  -10 },
        {{ -10,  -10 },  -10 },
        {{   0, +100 }, +100 },
        {{   0,    0 },    0 },
        {{-100,    0 },    0 }
    };

    for (const auto &Payload : TestData)
    {
        const auto &[ValueA, ValueB] = Payload.TestValues;
        TestTrueExpr(FMath::Max(ValueA, ValueB) == Payload.ExpectedValue);
    }

    /*
    TestTrue("Two Different Positive int32", FMath::Max(10, 100) == 100);
    TestTrue("Two Equal Positive int32", FMath::Max(10, 10) == 10);

    TestEqual("Two Different Negative int32", FMath::Max(-10, -100), -10);
    TestEqual("Two Equal Negative int32", FMath::Max(-10, -10), -10);

    TestTrue("Zero and Positive int32", FMath::Max(0, 100) == 100);
    TestTrue("Two Zeroes int32", FMath::Max(0, 0) == 0);
    TestTrue("Zero and Negative int32", FMath::Max(-100, 0) == 0);

    TestTrueExpr(FMath::Max(0, 100) == 100);
    TestTrueExpr(FMath::Max(0, 0) == 0);
    TestTrueExpr(FMath::Max(-100, 0) == 0);
    */

    return true;
}



IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathSqrtTest, TEXT("UE5_Tests.Math.Sqrt"),
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FMathSqrtTest::RunTest(const FString &Parameters)
{
    AddInfo("FMath::Sqrt Testing");

    struct TestPayload
    {
        float TestValue;
        float ExpectedValue;
        float Tolerance;
    };

    TArray<TestPayload> TestData =
    {
        { 4.0f,     2.0f, KINDA_SMALL_NUMBER },
        { 3.0f,     1.7f,               0.1f },
        { 3.0f,    1.73f,              0.01f },
        { 3.0f, 1.73205f, KINDA_SMALL_NUMBER }
    };

    for (const auto &Payload : TestData)
    {
        TestTrueExpr(FMath::IsNearlyEqual(FMath::Sqrt(Payload.TestValue), Payload.ExpectedValue, Payload.Tolerance));
    }

    /*
    TestEqual("FMath::Sqrt(4) [0]", FMath::Sqrt(4.0f), 2.0f);
    TestEqual("FMath::Sqrt(4) [1]", FMath::Sqrt(3.0f), 1.7f, 0.1f);
    TestEqual("FMath::Sqrt(3) [2]", FMath::Sqrt(3.0f), 1.73f, 0.01f);
    TestEqual("FMath::Sqrt(0) [3]", FMath::Sqrt(3.0f), 1.73205f);
    */

    return true;
}

#endif
