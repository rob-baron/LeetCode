#include <vector>
using namespace std;

class Solution
{
    void swap(int &a, int &b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        int nums_size = nums.size();
        int act_k = k % nums_size;
        int act_kp = nums_size - act_k;

        if (act_k > 0)
        {
            vector<int> tmp_array;
            int x;
            for (x = 0; x < act_kp; x++)
            {
                tmp_array.push_back(nums[x]);
            }
            for (x = act_kp; x < nums_size; x++)
            {
                nums[x - act_kp] = nums[x];
            }
            int y = 0;
            for (x = nums_size - act_kp; x < nums_size; x++)
            {
                nums[x] = tmp_array[y];
                y++;
            }
#ifdef TOO_SLOW
            int x, y;
            for (y = 0; y < nums_size - act_k; y++)
            {
                for (x = 0; x < nums_size - 1; x++)
                {
                    swap(nums[x], nums[(x + 1)]);
                }
            }
#endif
        }
    }
    //  5 6 7 1 2 3 4

    //  1 2 3 4 5 6 7   // 1 2 3 4 5 6 7  // 1 2 3 4 5 6 7
    //  2 1 3 4 1 6 7   // 3 2 1 4 5 6 7  // 4 2 3 1 5 6 7
    //  2 3 1 4 1 2 3   // 3 4 1 2 5 6 7  // 4 5 3 1 2 6 7
    //  2 3 4 1 5 6 7   // 3 4            // 4 5 6 1 2 3 7
};