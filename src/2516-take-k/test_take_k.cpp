#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "take_k.cpp"

namespace
{

    typedef struct
    {
        string s;
        int k;
        int ans;
    } test_case;

    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, take_k)
    {
        Solution sol;

        test_case tc[] = {{"aaabbbccc", 3, 9},
                          {"aaaabbbccc", 3, 9},
                          {"a", 3, -1},
                          {"aabaaaacaabc", 2, 8},
                          {"caaababcaa", 2, 7}};
        int x;
        for (x = 4; x < 5; x++)
        {

            int val = sol.takeCharacters(tc[x].s, tc[x].k);
            EXPECT_EQ(tc[x].ans, val) << x << " failed " << std::endl;
        }
    }

}