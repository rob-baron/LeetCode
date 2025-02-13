#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "gen_parens.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, gen_parens)
    {
        Solution gp;

        std::vector<string> vec, v0 = {""};
        int n = 0;
        vec = gp.generateParenthesis(n);
        EXPECT_EQ(vec, v0) << vec.size() << "is not 0" << std::endl;

        std::vector<string> v1 = {"()"};
        n = 1;
        vec = gp.generateParenthesis(n);
        EXPECT_EQ(vec, v1) << vec[0] << " != " << v1[0] << std::endl;

        std::vector<string> v2 = {"(())", "()()"};
        n = 2;
        vec = gp.generateParenthesis(n);
        EXPECT_EQ(vec, v2) << '[' << vec[0] << ',' << vec[1] << "] != ["
                           << v2[0] << ',' << v2[1] << "]" << std::endl;
    }

}