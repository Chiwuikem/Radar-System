#include "../include/InterceptCalculator.h"
#include "../include/Target.h"
#include <gtest/gtest.h>

TEST(InterceptTests, PredictsFuturePosition)
{
    InterceptCalculator calculator;
    Target target(1, 0, 0, 10, 0);

    auto position = calculator.predictPosition(target, 5);

    EXPECT_NEAR(position.first, 50, 0.01);
    EXPECT_NEAR(position.second, 0, 0.01);
}

TEST(InterceptTests, CalculatesSuccessProbability)
{
    InterceptCalculator calculator;
    Target target(2, 100, 100, 10, 180);

    double probability = calculator.calculateSuccessProbability(target, 5);

    EXPECT_GE(probability, 0);
    EXPECT_LE(probability, 100);
}