#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class match_state
{
private:
    int pi;
    int si;
    int last_pstar;
    int last_sstar;

    match_state()
    {
        pi = 0;
        si = 0;
        last_pstar = -1;
        last_sstar = -1;
    }

public:
    match_state(int p_index, int s_index)
    {
        pi = p_index;
        si = s_index;
    }
    int get_pindex() { return pi; }
    int get_sindex() { return si; }
    void inc_pindex() { pi++; }
    void inc_sindex() { si++; }
    void set_star()
    {
        last_pstar = pi;
        last_sstar = si + 1;
    }
    void reset_pindex()
    {
        if (last_pstar > -1)
        {
            pi = last_pstar;
            si = last_sstar;
            last_sstar++;
        }
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        /* preprocess pattern, eliminate "**" */
        int x1 = 0, x2 = 0, p_size = p.size(), s_size = s.size();
        char *s_cstr, *p_cstr;
        s_cstr = (char *)calloc(sizeof(char), s_size + 1);
        p_cstr = (char *)calloc(sizeof(char), p_size + 1);
        memcpy(s_cstr, s.c_str(), s_size);
        memcpy(p_cstr, p.c_str(), p_size);

        match_state ms(0, 0);
        char pat_ch, s_ch;
        int state = 1;
        while (state)
        {
            switch (state)
            {
            case 1:
                pat_ch = p_cstr[ms.get_pindex()];
                if (('A' <= pat_ch && pat_ch <= 'Z') || ('a' <= pat_ch && pat_ch <= 'z'))
                {
                    state = 2;
                }
                else if (pat_ch == '?')
                {
                    state = 3;
                }
                else if (pat_ch == '*')
                {
                    if (p_cstr[ms.get_pindex() + 1])
                        state = 4;
                    else
                        return true;
                }
                else if (pat_ch == '\0' && s_cstr[ms.get_sindex()] == '\0')
                {
                    return true;
                }
                else
                    return false;
                break;
            case 2:
                /* pattern character == [A-Za-z] */
                if (pat_ch == s_cstr[ms.get_sindex()])
                {
                    ms.inc_pindex();
                    ms.inc_sindex();
                    state = 1;
                }
                else
                {
                    return false;
                }
                break;
            case 3:
                /* patern character == '?' */
                ms.inc_pindex();
                if (s_cstr[ms.get_sindex()] == '\0')
                    return false;
                ms.inc_sindex();
                state = 1;
                break;
            case 4:
                /* pattern character == '*' */
                pat_ch = p_cstr[ms.get_pindex()];
                if (pat_ch == '*')
                {
                    ms.set_star();
                    ms.inc_pindex();
                    /* if the next character in the pattern is a '\0' then * is at the end and we accept */
                    if (p_cstr[ms.get_pindex()] == '\0')
                        return true;
                    /* state = 4 */
                }
                else if (pat_ch == '\0' && s_cstr[ms.get_sindex()] == '\0')
                    return true;
                else if (('A' <= pat_ch && pat_ch <= 'Z') || ('a' <= pat_ch && pat_ch <= 'z'))
                    state = 5;
                else if (pat_ch == '?')
                    state = 6;
                else if (pat_ch == '\0')
                    ms.reset_pindex();
                else
                    return false;
                break;
            case 5:
                /* p ch = [A-Za-z] after a '*' */
                s_ch = s_cstr[ms.get_sindex()];
                pat_ch = p_cstr[ms.get_pindex()];
                if (s_ch == '\0')
                {
                    return false;
                }
                else if (pat_ch == s_ch)
                {
                    ms.inc_pindex();
                    ms.inc_sindex();
                    state = 4;
                }
                else
                {
                    ms.reset_pindex();

                    state = 4;
                }
                break;
            case 6:
                /* p ch = ? after a '*' */
                if (s_cstr[ms.get_sindex()] == '\0')
                    return false;
                else
                {
                    ms.inc_pindex();
                    ms.inc_sindex();
                }
                state = 4;
                break;
            }
        }
        return false;
    }

    bool isMatch2(string s, string p)
    {
        /* preprocess pattern, eliminate "**" */
        int x1 = 0, x2 = 0, p_size = p.size(), s_size = s.size();
        char *s_cstr, *p_cstr;
        s_cstr = (char *)calloc(sizeof(char), s_size + 1);
        p_cstr = (char *)calloc(sizeof(char), p_size + 1);
        memcpy(s_cstr, s.c_str(), s_size);
        memcpy(p_cstr, p.c_str(), p_size);
        while (p_cstr[x1])
        {
            if (p_cstr[x1] == '*' && p_cstr[x2] == '*')
            {
                x2++;
            }
            if (p_cstr[x1] == '*' && p_cstr[x2] != '*')
            {
                x1++;
                p_cstr[x1] = p_cstr[x2];
            }
            else if (p_cstr[x1] != '*')
            {
                if (p_cstr[x1])
                    x1++;
                if (p_cstr[x2])
                    x2++;
                if (x1 != x2)
                    p_cstr[x1] = p_cstr[x2];
            }
        }

        int s_index = 0;
        queue<match_state *> ms_q;
        match_state *ms2;
        ms_q.push(new match_state(0, 0));

        while (ms_q.size() > 0)
        {
            match_state *ms;
            ms = ms_q.front();
            ms_q.pop();
            switch (p_cstr[ms->get_pindex()])
            {
            case '?':
                if (ms->get_sindex() < s_size)
                {
                    ms->inc_pindex();
                    ms->inc_sindex();
                }
                else
                {
                    delete ms;
                    ms = NULL;
                }
                break;
            case '*':
                if (ms->get_sindex() < s_size)
                {
                    ms2 = new match_state(ms->get_pindex(), ms->get_sindex());
                    ms2->inc_sindex();
                    ms_q.push(ms2);
                }
                ms->inc_pindex();
                break;
            default:
                if ('a' <= p_cstr[ms->get_pindex()] && p_cstr[ms->get_pindex()] <= 'z')
                {
                    if (p_cstr[ms->get_pindex()] == s_cstr[ms->get_sindex()])
                    {
                        ms->inc_pindex();
                        ms->inc_sindex();
                    }
                    else
                    {
                        delete ms;
                        ms = NULL;
                    }
                }
            }
            if (ms)
            {
                if (s_cstr[ms->get_sindex()] == '\x00' && p_cstr[ms->get_pindex()] == '\x00')
                {
                    delete ms;
                    while (ms_q.size() && (ms = ms_q.front()))
                    {
                        delete ms;
                        ms_q.pop();
                    }
                    return true;
                }
                else if (p_cstr[ms->get_pindex()] == '\x00')
                {
                    delete ms;
                    ms = NULL;
                }
                else
                {
                    ms_q.push(ms);
                }
            }
        }
        return false;
    }
};