#include "macrodef.h"

TEST(macrodef, jmax){
    EXPECT_EQ(1, J_Max(1, 0));
    EXPECT_EQ(0, J_Max(-1, 0));
}

TEST(macrodef, jclamp){
    EXPECT_EQ(3, J_Clamp(3, 0, 5));
    EXPECT_EQ(0, J_Clamp(-1, 0, 5));
    EXPECT_EQ(5, J_Clamp(6, 0, 5));
}

