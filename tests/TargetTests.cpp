#include "../include/Target.h"
#include <gtest/gtest.h>

TEST(TargetTests, UpdatesPositionCorrectly)
{
    Target target(1, 0, 0, 10, 0);

    target.updatePosition(1);

    EXPECT_NEAR(target.getX(), 10, 0.01);
    EXPECT_NEAR(target.getY(), 0, 0.01);
}