#include "gtest/gtest.h"
#include "../uniLib/include/uniLib.h"

TEST(SquareRootTest, PositiveNos) {
    EXPECT_EQ(18.0, 18.0);
}

TEST(ValidGradeTest, ZeroAndNegative) {
    EXPECT_FALSE(isGradeValid(0));
    EXPECT_FALSE(isGradeValid(-3));
    EXPECT_FALSE(isGradeValid(-150));
}

TEST(ValidGradeTest, PositiveAndLarge) {
    EXPECT_FALSE(isGradeValid(1));
    EXPECT_FALSE(isGradeValid(3));
    EXPECT_TRUE(isGradeValid(4));
    EXPECT_TRUE(isGradeValid(9));
    EXPECT_TRUE(isGradeValid(10));
    EXPECT_FALSE(isGradeValid(255));
}