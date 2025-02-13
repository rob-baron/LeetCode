#include <list>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        list<char> stack;
        char ch;
        for (ch in s)
        {
            switch (ch)
            {
            case '{':
                stack.push_front('}');
                break;
            case '(':
                stack.push_front(')');
                break;
            case '[':
                stack.push_front(']');
                break;
            case ')':
            case '}':
            case ']':
                if (stack.size() > 0)
                {
                    if (ch == stack.front())
                    {
                        stack.pop_front();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (stack.size() == 0)
        {
            return true;
        }
        return false;
    }
};