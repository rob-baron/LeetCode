#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// #define BRUTEFORCE

class Solution
{
public:
    typedef struct
    {
        int index_1;
        int index_2;
        int value;
    } nums_t;

    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret_val;
        ret_val.push_back(-1);
        ret_val.push_back(-1);

#ifdef BRUTEFORCE
        // The search space is n x n, but since
        // addition is associative, it is 1/2
        // Brute force O(n^2)
        int i = 0, j = 1;
        int nums_size = nums.size();
        while (i < nums_size - 1 && j < nums_size && nums[i] + nums[j] != target)
        {
            j++;
            if (j >= nums_size)
            {
                i++;
                j = i + 1;
            }
        }

        if (nums[i] + nums[j] == target)
        {
            ret_val[0] = i;
            ret_val[i] = j;
        }
#else // much faster O(n)
        unordered_map<int, int> vals;
        int x;
        for (x = 0; x < nums.size() && ret_val[0] == -1; x++)
        {
            auto it = vals.find(target - nums[x]);
            if (it != vals.end())
            {
                ret_val[0] = it->second;
                ret_val[1] = x;
            }
            vals.insert({nums[x], x});
        }
#endif
        return ret_val;
    }
};