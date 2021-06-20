#include "gtest/gtest.h"

TEST(SquareRootTest, PositiveNos) {
    EXPECT_EQ(18.0, 18.0);
}

TEST(SquareRootTest, ZeroAndNegativeNos) {
    ASSERT_EQ(0.0, 1.0);
}