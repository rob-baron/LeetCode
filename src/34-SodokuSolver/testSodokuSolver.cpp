#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "wildcard_match.cpp"

using namespace std;

namespace
{

    typedef struct
    {
        vector<vector<char>> board;
        vector<vector<char>> ans;
    } test_case;

    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, Sodoku)
    {
        Solution sol;
        test_case tc[] = {{{
                               {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
                           },
                           {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}}}};
        int x;
        for (x = 0; x < 17; x++)
        {
            bool val = sol.isMatch(tc[x].s, tc[x].p);
            EXPECT_EQ(tc[x].ans, val) << x << " failed " << tc[x].s << " - pattern " << tc[x].p << std::endl;
        }
    }
}