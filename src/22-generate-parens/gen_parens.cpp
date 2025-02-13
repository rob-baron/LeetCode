#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set>
using namespace std;

class Solution
{
    // This is slow.
    void gen_parens(unordered_set<string> *ret_val, int depth, string current, char start, char *prod)
    {
        // unordered_set<string> ret_val;
        int current_size = current.size();
        int x;
        if (depth > 0)
        {
            string first, second;
            for (x = 0; x < current_size; x++)
            {
                if (current[x] == start)
                {
                    first = current.substr(0, x + 1);
                    second = current.substr(x + 1, current_size - x);
                    // ret_val.merge(gen_parens(depth - 1, first + prod + second, start, prod));
                    gen_parens(ret_val, depth - 1, first + prod + second, start, prod);
                }
            }
        }
        else
        {
            // replace the
            string final_str;
            for (x = 0; x < current.size(); x++)
            {
                if (current[x] != start)
                    final_str.push_back(current[x]);
            }
            ret_val->insert(final_str);
        }
    }

    void gen_parens2(unordered_set<string> *ret_val, int depth, char *current, char start, string prod)
    {
        // unordered_set<string> ret_val;
        int x;
        if (depth > 0)
        {
            char *pos = current;
            char tmp_str[100] = "";
            int x = 0;
            while (*pos)
            {
                if (*pos == start)
                {
                    strcat(tmp_str, prod);
                    strcat(tmp_str, *(pos + 1));
                }
                else
                {
                    tmp_str[x] = *pos;
                    tmp_str[x + 1] = 0;
                }
            }
            for (x = 0; x < current_size; x++)
            {
                if (current[x] == start)
                {
                    first = current.substr(0, x + 1);
                    second = current.substr(x + 1, current_size - x);
                    // ret_val.merge(gen_parens(depth - 1, first + prod + second, start, prod));
                    gen_parens(ret_val, depth - 1, first + prod + second, start, prod);
                }
            }
        }
        else
        {
            // replace the
            string final_str;
            for (x = 0; x < current.size(); x++)
            {
                if (current[x] != start)
                    final_str.push_back(current[x]);
            }
            ret_val->insert(final_str);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        unordered_set<string> paren_set;
        gen_parens(&paren_set, n, "S", 'S', "(S)S");
        vector<string> paren_vec(paren_set.begin(), paren_set.end());
        sort(paren_vec.begin(), paren_vec.end());
        return paren_vec;
    }
};