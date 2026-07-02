#include "../include/ThreatDetector.h"
#include "../include/Target.h"
#include <gtest/gtest.h>

TEST(ThreatTests, ClassifiesCloseFastTargetAsCritical)
{
    ThreatDetector detector;
    Target target(1, 50, 50, 25, 180);

    EXPECT_EQ(detector.classifyThreat(target), "CRITICAL");
}

TEST(ThreatTests, CalculatesThreatScore)
{
    ThreatDetector detector;
    Target target(2, 100, 100, 20, 225);

    double score = detector.calculateThreatScore(target);

    EXPECT_GT(score, 0);
    EXPECT_LE(score, 100);
}