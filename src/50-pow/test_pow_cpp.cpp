#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "pow.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, pow)
    {
        Solution pow;
        int x;
        for (x = 0; x < 10; x++)
        {
            double val = pow.myPow(2, x);
            EXPECT_EQ(val, std::pow(2.0, x * 1.0)) << "pow(2, " << x << ") failed" << std::endl;
        }
    }

    TEST(Solution, pow_2_10)
    {
        Solution pow;
        EXPECT_EQ(pow.myPow(2.0, 10.0), std::pow(2.0, 10));
    }

    TEST(Solution, pow)
    {
        Solution pow;
        int x;
        for (x = 0; x > -10; x--)
        {
            double val = pow.myPow(2, x);
            EXPECT_EQ(val, std::pow(2.0, x * 1.0)) << "pow(2, " << x << ") failed" << std::endl;
        }
    }
}