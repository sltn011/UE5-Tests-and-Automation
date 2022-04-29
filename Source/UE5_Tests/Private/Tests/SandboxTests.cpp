// Fill out your copyright notice in the Description page of Project Settings.


#include "Tests/SandboxTests.h"
#include "CoreMinimal.h"

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxInt, TEXT("UE5_Tests.Math.MaxInt"),
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FMathMaxInt::RunTest(FString const &Parameters)
{
    TestTrue("Two Different Positive int32", FMath::Max(10, 100) == 100);
    TestTrue("Two Equal Positive int32", FMath::Max(10, 10) == 10);

    TestTrue("Two Different Negative int32", FMath::Max(-10, -100) == -10);
    TestTrue("Two Equal Negative int32", FMath::Max(-10, -10) == -10);

    TestTrue("Zero and Positive int32", FMath::Max(0, 100) == 100);
    TestTrue("Two Zeroes int32", FMath::Max(0, 0) == 0);
    TestTrue("Zero and Negative int32", FMath::Max(-100, 0) == 0);

    return true;
}