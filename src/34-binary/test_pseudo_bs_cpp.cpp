#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "pseudo_bs.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, pseudo_bs)
    {
        Solution sr;

        std::vector<int> vec1 = {5, 7, 7, 8, 8, 10}, out_vec;
        int target1 = 8;
        out_vec = sr.searchRange(vec1, target1);
        EXPECT_EQ(out_vec[0], 3) << "1 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 4) << "1 out_vec[1]=" << out_vec[1] << std::endl;

        target1 = 7;
        out_vec = sr.searchRange(vec1, target1);
        EXPECT_EQ(out_vec[0], 1) << "2 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 2) << "2 out_vec[1]=" << out_vec[1] << std::endl;

        target1 = 3;
        out_vec = sr.searchRange(vec1, target1);
        EXPECT_EQ(out_vec[0], -1) << "3 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], -1) << "3 out_vec[1]=" << out_vec[1] << std::endl;

        std::vector<int> vec2 = {7, 7, 7, 7, 7, 7};
        target1 = 7;
        out_vec = sr.searchRange(vec2, target1);
        EXPECT_EQ(out_vec[0], 0) << "4 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 5) << "4 out_vec[1]=" << out_vec[1] << std::endl;

        std::vector<int> vec3 = {2, 2};
        target1 = 2;
        out_vec = sr.searchRange(vec3, target1);
        EXPECT_EQ(out_vec[0], 0) << "5 out_vec[0]=" << out_vec[0] << std::endl;
        EXPECT_EQ(out_vec[1], 1) << "5 out_vec[1]=" << out_vec[1] << std::endl;
    }

}