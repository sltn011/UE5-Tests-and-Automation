// Fill out your copyright notice in the Description page of Project Settings.


#include "Tests/SandboxTests.h"
#include "CoreMinimal.h"

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxIntTest, TEXT("UE5_Tests.Math.MaxInt"),
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FMathMaxIntTest::RunTest(FString const &Parameters)
{
    AddInfo("FMath::Max<int32> Testing");

    TestTrue("Two Different Positive int32", FMath::Max(10, 100) == 100);
    TestTrue("Two Equal Positive int32", FMath::Max(10, 10) == 10);

    TestEqual("Two Different Negative int32", FMath::Max(-10, -100), -10);
    TestEqual("Two Equal Negative int32", FMath::Max(-10, -10), -10);

    //TestTrue("Zero and Positive int32", FMath::Max(0, 100) == 100);
    //TestTrue("Two Zeroes int32", FMath::Max(0, 0) == 0);
    //TestTrue("Zero and Negative int32", FMath::Max(-100, 0) == 0);

    TestTrueExpr(FMath::Max(0, 100) == 100);
    TestTrueExpr(FMath::Max(0, 0) == 0);
    TestTrueExpr(FMath::Max(-100, 0) == 0);


    return true;
}



IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathSqrtTest, TEXT("UE5_Tests.Math.Sqrt"),
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FMathSqrtTest::RunTest(const FString &Parameters)
{
    AddInfo("FMath::Sqrt Testing");

    TestEqual("FMath::Sqrt(4) [0]", FMath::Sqrt(4.0f), 2.0f);
    TestEqual("FMath::Sqrt(4) [1]", FMath::Sqrt(3.0f), 1.7f, 0.1f);
    TestEqual("FMath::Sqrt(3) [2]", FMath::Sqrt(3.0f), 1.73f, 0.01f);
    TestEqual("FMath::Sqrt(0) [3]", FMath::Sqrt(3.0f), 1.73205f);

    return true;
}
