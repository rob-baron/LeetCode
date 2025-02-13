#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        list<int> stack;

        for (string &tok : tokens)
        {
            int val1, val2, val3;
            if (tok.compare("+") == 0)
            {
                if (stack.size() > 1)
                {
                    val2 = stack.front();
                    stack.pop_front();
                    val1 = stack.front();
                    stack.pop_front();
                    val3 = val1 + val2;
                    stack.push_front(val3);
                }
            }
            else if (tok.compare("-") == 0)
            {
                if (stack.size() > 1)
                {
                    val2 = stack.front();
                    stack.pop_front();
                    val1 = stack.front();
                    stack.pop_front();
                    val3 = val1 - val2;
                    stack.push_front(val3);
                }
            }
            else if (tok.compare("*") == 0)
            {
                if (stack.size() > 1)
                {
                    val2 = stack.front();
                    stack.pop_front();
                    val1 = stack.front();
                    stack.pop_front();
                    val3 = val1 * val2;
                    stack.push_front(val3);
                }
            }
            else if (tok.compare("/") == 0)
            {
                if (stack.size() > 1)
                {
                    val2 = stack.front();
                    stack.pop_front();
                    val1 = stack.front();
                    stack.pop_front();
                    val3 = val1 / val2;
                    stack.push_front(val3);
                }
            }
            else
            {
                stack.push_front(atoi(tok.c_str()));
            }
        }
        return stack.front();
    }
};