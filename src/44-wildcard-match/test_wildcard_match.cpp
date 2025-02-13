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
        string s;
        string p;
        bool ans;
    } test_case;

    /* P04 (*) Find the number of elements of a list. */
    TEST(Solution, WildcardMatch)
    {
        Solution sol;
        test_case tc[] = {
            /* 0 */ {"", "?", false},
            /* 1 */ {"ab", "?*", true},
            /* 2 */ {"aa", "a", false},
            /* 3 */ {"aa", "?a", true},
            /* 4 */ {"cb", "?a", false},
            /* 5 */ {"aa", "??", true},
            /* 6 */ {"aa", "aa", true},
            /* 7 */ {"aa", "a?", true},
            /* 8 */ {"aa", "*", true},
            /* 9 */ {"aa", "*a", true},
            /* 10 */ {"aa", "a*", true},
            /* 11 */ {"a", "*a*", true},
            /* 12 */ {"aa", "*a*a*", true},
            /* 13 */ {"aaa", "aaa***", true},
            /* 14 */ {"abefcdgiescdfimde", "ab*cd?i*de", true},
            /* 15 */ {"abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab", "*aabb***aa**a******aa*", true},
            /* 16 */ {"abcabczzzde", "*abc???de*", true}};
        int x;
        for (x = 0; x < 17; x++)
        {
            bool val = sol.isMatch(tc[x].s, tc[x].p);
            EXPECT_EQ(tc[x].ans, val) << x << " failed " << tc[x].s << " - pattern " << tc[x].p << std::endl;
        }
    }
}