#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    /* interesting, leet code gave different runtimes for this code
     * for each run of this code, from 5ms to 30ms.
     */
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> umap;
        int prefix_count = 0;
        int size_a = a.size();
        int x;
        vector<int> ret_val;
        for (x = 0; x < size_a; x++)
        {
            umap[a[x]]++;
            umap[b[x]]++;
            if (umap[a[x]] == 2)
            {
                prefix_count++;
                umap[a[x]]++;
            }
            if (umap[b[x]] == 2)
            {
                prefix_count++, umap[b[x]]++;
            }
            ret_val.push_back(prefix_count);
        }
        return ret_val;
    }
};