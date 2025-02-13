#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    // basic productions
    //   S -> E
    //   E -> T
    //   E -> ( E )
    //   T -> n
    //   T -> + T
    //   T -> T + n
public:
    long calculate(string s)
    {
        long ret_val, operand;
        switch (s[0])
        {
        case '(':
        case ')':
        case '+':
        case '-':
        default:
            operand = 0;
            while ('0' <= s[0] && s[0] <= '9')
                operand = 10 * operand + s[0] - '0';
            s.erase(s.begin());
        }
        return ret_val;
    }
};