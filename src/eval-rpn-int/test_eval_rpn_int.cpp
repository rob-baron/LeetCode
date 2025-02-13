#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "eval_rpn_int.cpp"

namespace
{
    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, evalRpmInt)
    {
        Solution eval_rpn;

        std::vector<string> rpn = {"2", "1", "+", "3", "*"};
        int val;
        val = eval_rpn.evalRPN(rpn);
        EXPECT_EQ(val, 9) << "1 evalRPN=" << val << " Should be 9" << std::endl;
    }

}
