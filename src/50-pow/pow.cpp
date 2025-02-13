
#include <list>

using namespace std;

class Solution
{
    double myPowStackRecursion(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n % 2)
        {
            return x * myPow(x, n - 1);
        }
        else
        {
            double result = myPow(x, n / 2);
            return result * result;
        }
    }

    double myPowExplicitStack(double x, int n)
    {
        list<bool> div_flag;
        long np = n;
        if (n < 0)
        {
            np = (long)-1 * n;
        }
        while (np > 0)
        {
            if (np % 2)
            {
                div_flag.push_front(false);
                np = np - 1;
            }
            else
            {
                div_flag.push_front(true);
                if (np > 2)
                {
                    np = np / 2;
                }
                else
                {
                    np = np - 2;
                }
            }
        }
        double ret_val = 1;
        while (div_flag.size() > 0)
        {
            if (div_flag.front() == true)
            {
                /* squaring */
                if (ret_val == 1)
                    ret_val = x;
                ret_val = ret_val * ret_val;
            }
            else
            {
                ret_val = ret_val * x;
            }
            div_flag.pop_front();
        }
        if (n < 0)
        {
            ret_val = 1.0 / ret_val;
        }
        return ret_val;
    }

public:
    double myPow(double x, int n)
    {
        return myPowExplicitStack(x, n);
    }
};
