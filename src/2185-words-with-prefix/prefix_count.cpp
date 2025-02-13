#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    bool has_prefix(const char *str, const char *prefix)
    {
        if (!prefix)
            return true;
        if (str && prefix)
        {
            int x = 0;
            while (prefix[x] && str[x] == prefix[x])
            {
                x++;
            }
            if (prefix[x] == 0)
                return true;
        }
        return false;
    }

public:
    int prefixCount(vector<string> &words, string pref)
    {
        int vec_len = words.size();
        int x;
        int cnt = 0;
        for (x = 0; x < vec_len; x++)
        {
            if (has_prefix(words[x].c_str(), pref.c_str()))
            {
                cnt++;
            }
        }
        return cnt;
    }
};