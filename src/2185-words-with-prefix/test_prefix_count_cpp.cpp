#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "prefix_count.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, pow)
    {
        Solution pc;

        vector<string> input_1 = {"pay", "attention", "practice", "attend"};
        string prefix_1 = "at";
        int val = pc.prefixCount(input_1, prefix_1);
        EXPECT_EQ(val, 2) << "prefixCount 1 failed" << std::endl;
    }

}