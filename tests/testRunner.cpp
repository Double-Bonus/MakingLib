#include "gtest/gtest.h"
#include "../uniLib/include/uniLib.h"

TEST(ValidGradeTest, ZeroAndNegative) {
    EXPECT_FALSE(isGradeValid(0));
    EXPECT_FALSE(isGradeValid(-3));
    EXPECT_FALSE(isGradeValid(-150));
    EXPECT_FALSE(isGradeValid(INT32_MIN));
}

TEST(ValidGradeTest, PositiveAndLarge) {
    EXPECT_FALSE(isGradeValid(1));
    EXPECT_FALSE(isGradeValid(3));
    EXPECT_TRUE(isGradeValid(40));
    EXPECT_TRUE(isGradeValid(90));
    EXPECT_TRUE(isGradeValid(100));
    EXPECT_FALSE(isGradeValid(255));
    EXPECT_FALSE(isGradeValid(INT32_MAX));
}


TEST(LithuaniaGetTest, CheckCountAllLit) 
{
    const uint32_t len = 4;
    uint32_t result;
    uint32_t out_index[len] = { 0 };

    sUniData test_data[len] = {
     {"KTU", "Math", "Lithuania", 50},
     {"KTU", "Math", "Lithuania", 50},
    {"KTU", "Math", "Lithuania", 50},
    {"KTU", "Math", "Lithuania", 50}
    };

    result = getLitCountries(test_data, len, out_index);
    EXPECT_EQ(result, 4);
    EXPECT_EQ(out_index[0], 0);
    EXPECT_EQ(out_index[1], 1);
    EXPECT_EQ(out_index[2], 2);
    EXPECT_EQ(out_index[3], 3);
}

TEST(LithuaniaGetTest, CheckCountNoLit) 
{
    const uint32_t len = 4;
    uint32_t result = 0;
    uint32_t out_index[len] = { 0 };

    sUniData test_data[len] = {
    {"Hardvard", "Math", "USA", 50},
    {"Lund", "Math", "Sweden", 50},
    {"UCL", "Math", "USA", 50},
    {"Yale", "Math", "USA", 50}
    };

    result = getLitCountries(test_data, len, out_index);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(out_index[0], 0);
    EXPECT_EQ(out_index[1], 0);
    EXPECT_EQ(out_index[2], 0);
    EXPECT_EQ(out_index[3], 0);
}


TEST(LithuaniaGetTest, CheckCountFewLit) 
{
    const uint32_t len = 4;
    uint32_t result = 0;
    uint32_t out_index[len] = { 0 };

    sUniData test_data[len] = {
    {"KTU", "Math", "Lithuania", 50},
    {"Lund", "Math", "Sweden", 50},
    {"KTU", "Math", "Lithuania", 50},
    {"Yale", "Math", "USA", 50}
    };

    result = getLitCountries(test_data, len, out_index);
    EXPECT_EQ(result, 2);
    EXPECT_EQ(out_index[0], 0);
    EXPECT_EQ(out_index[1], 2);
    EXPECT_EQ(out_index[2], 0);
    EXPECT_EQ(out_index[3], 0);
}

TEST(LithuaniaGetTest, CheckCountCapital) 
{
    const uint32_t len = 4;
    uint32_t result = 0;
    uint32_t out_index[len] = { 0 };

    sUniData test_data[len] = {
    {"KTU", "Math", "LithuaniA", 50},
    {"KTU", "Math", "Lihtuania", 50},
    {"KTU", "Math", "Lithunia", 50},
    {"KTU", "Math", "LITHUANIA", 50}
    };

    result = getLitCountries(test_data, len, out_index);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(out_index[0], 0);
    EXPECT_EQ(out_index[1], 0);
    EXPECT_EQ(out_index[2], 0);
    EXPECT_EQ(out_index[3], 0);
}