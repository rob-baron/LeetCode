#include <string>

using namespace std;

class counts
{
private:
    int cnt_a;
    int cnt_b;
    int cnt_c;
    int total;

public:
    counts()
    {
        cnt_a = 0;
        cnt_b = 0;
        cnt_c = 0;
        total = 0;
    }

    int add(char ch)
    {
        if (ch)
        {
            switch (ch)
            {
            case 'a':
                cnt_a++;
                total++;
                break;
            case 'b':
                cnt_b++;
                total++;
                break;
            case 'c':
                cnt_c++;
                total++;
                break;
            default:
                return 0;
            }
            return 1;
        }
        return 0;
    }

    int del(char ch)
    {
        if (ch)
        {
            switch (ch)
            {
            case 'a':
                cnt_a--;
                total--;
                break;
            case 'b':
                cnt_b--;
                total--;
                break;
            case 'c':
                cnt_c--;
                total--;
                break;
            default:
                return 0;
            }
            return 1;
        }
        return 0;
    }

    int get_cnt_a() { return cnt_a; }
    int get_cnt_b() { return cnt_b; }
    int get_cnt_c() { return cnt_c; }
    int get_total() { return total; }

    int check_tallies(counts *c2, int k)
    {
        if ((cnt_a + c2->get_cnt_a()) < k || (cnt_b + c2->get_cnt_b()) < k || (cnt_c + c2->get_cnt_c()) < k)
        {
            return -1;
        }
        return 1;
    }

    int get_total(counts *c2)
    {
        return total + c2->get_total();
    }
};

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int x, y, s_size = s.size();
        int ret_val;
        counts c1, c2;
        x = 0;
        while (x < s_size && c1.check_tallies(&c2, k) == -1)
        {
            c1.add(s[x]);
            x++;
        }
        if (x == s_size)
        {
            if (c1.check_tallies(&c2, k) == -1)
            {
                return -1;
            }
        }
        x--;
        ret_val = c1.get_total(&c2);
        y = s_size - 1;
        while (y >= 0)
        {
            c2.add(s[y]);
            y--;
            while (x >= 0 && c1.check_tallies(&c2, k) == 1)
            {
                c1.del(s[x]);
                x--;
            }
            if (c1.check_tallies(&c2, k) == -1)
            {
                x++;
                c1.add(s[x]);
            }
            if (c1.get_total(&c2) < ret_val)
            {
                ret_val = c1.get_total(&c2);
            }
        }
        return ret_val;
    }
};