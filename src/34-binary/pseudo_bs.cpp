#include <vector>

using namespace std;

class Solution
{

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int upper_bound = nums.size();
        int lower_bound = 0;
        int middle = upper_bound / 2;
        vector<int> ret_val;
        ret_val.push_back(-1);
        ret_val.push_back(-1);
        if (nums.size() > 0)
        {
            while (nums[middle] != target && upper_bound - lower_bound > 1)
            {
                if (nums[middle] != target)
                {
                    if (target < nums[middle])
                        upper_bound = middle;
                    else if (nums[middle] < target)
                        lower_bound = middle;
                    middle = lower_bound + (upper_bound - lower_bound) / 2;
                }
            }
            if (nums[middle] == target)
            {
                lower_bound = 0;
                if (nums[lower_bound] != target)
                {
                    /* work the lower bound */
                    int delta = (middle - lower_bound) / 2;
                    while (delta > 0)
                    {
                        int test = lower_bound + delta;
                        if (nums[test] == target)
                            middle = test;
                        else
                            lower_bound = test;
                        delta = (middle - lower_bound) / 2;
                    }
                    lower_bound = middle;
                }
                /* work the upper bound */
                upper_bound = nums.size() - 1;
                if (nums[upper_bound] != target)
                {
                    int delta = (upper_bound - middle) / 2;
                    while (delta > 0)
                    {
                        int test = middle + delta;
                        if (nums[test] == target)
                            middle = test;
                        else
                            upper_bound = test;
                        delta = (upper_bound - middle) / 2;
                    }
                    upper_bound = middle;
                }
                ret_val[0] = lower_bound;
                ret_val[1] = upper_bound;
            }
        }
        return ret_val;
    }
};