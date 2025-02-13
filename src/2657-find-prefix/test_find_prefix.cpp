#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "find_prefix.cpp"

using namespace std;

namespace
{

    typedef struct
    {
        vector<int> a;
        vector<int> b;
        vector<int> ans;
    } test_case;

    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, find_prefix)
    {
        Solution sol;
        test_case tc[] = {{{1, 3, 2, 4}, {3, 1, 2, 4}, {0, 2, 3, 4}}};
        int x;
        for (x = 0; x < 1; x++)
        {
            vector<int> val = sol.findThePrefixCommonArray(tc[x].a, tc[x].b);
            EXPECT_EQ(tc[x].ans, val) << x << " failed " << std::endl;
        }
    }
}