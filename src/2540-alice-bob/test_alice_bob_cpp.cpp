#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "alice_bob.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, TwoSum)
    {
        Solution basic_calc;

        std::vector<int> vec1 = {1, 2, 3, 4, 5}, out_vec;
        int target1 = 4;
        out_vec = two_sum.twoSum(vec1, target1);
        EXPECT_EQ(out_vec[0], 0) << "1 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 2) << "1 out_vec[1]=" << out_vec[1] << std::endl;
        ß
    }

}