#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "two_sum.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, TwoSum)
    {
        Solution two_sum;

        std::vector<int> vec1 = {1, 2, 3, 4, 5}, out_vec;
        int target1 = 4;
        out_vec = two_sum.twoSum(vec1, target1);
        EXPECT_EQ(out_vec[0], 0) << "1 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 2) << "1 out_vec[1]=" << out_vec[1] << std::endl;

        std::vector<int> vec2 = {2, 7, 11, 15};
        int target2 = 9;
        out_vec = two_sum.twoSum(vec2, target2);
        EXPECT_EQ(out_vec[0], 0) << "2 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 1) << "2 out_vec[1]=" << out_vec[1] << std::endl;

        std::vector<int> vec3 = {3, 2, 4};
        int target3 = 6;
        out_vec = two_sum.twoSum(vec3, target3);
        EXPECT_EQ(out_vec[0], 1) << "3 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 2) << "3 out_vec[1]=" << out_vec[1] << std::endl;

        std::vector<int> vec4 = {2, 7, 11, 15};
        int target4 = 9;
        out_vec = two_sum.twoSum(vec4, target4);
        EXPECT_EQ(out_vec[0], 0) << "4 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 1) << "4 out_vec[1]=" << out_vec[1] << std::endl;
    }

}
