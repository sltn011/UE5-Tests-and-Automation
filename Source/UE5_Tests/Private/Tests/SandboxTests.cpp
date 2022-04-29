// Fill out your copyright notice in the Description page of Project Settings.


#include "Tests/SandboxTests.h"
#include "CoreMinimal.h"

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxInt, TEXT("UE5_Tests.Math.MaxInt"),
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FMathMaxInt::RunTest(FString const &Parameters)
{
    return TestTrue("Two Different Positive int32", FMath::Max(10, 100) == 100);
}