#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "rotate_array.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, TwoSum)
    {
        Solution ra;

        std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7},
                         out_vec1 = {5, 6, 7, 1, 2, 3, 4};
        int k = 3;
        ra.rotate(vec1, k);
        EXPECT_EQ(out_vec1, vec1) << "1 didn't pass" << std::endl;
    }
}
