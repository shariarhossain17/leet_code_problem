#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool solved_using_brute_force(string &s, string &t)
    {

        string a = "", b = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (a.length() > 0)
                    a.erase(a.length() - 1);
            }

            else
                a += s[i];
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                if (b.length() > 0)
                    b.erase(b.length() - 1);
            }

            else
                b += t[i];
        }

        return a == b;
    }

    bool solve_using_better_solution(string &s, string &t)
    {
        stack<char> a, b;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '#')
                a.push(s[i]);
            else
            {
                if (!a.empty())
                    a.pop();
            }
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] != '#')
                b.push(t[i]);
            else
            {
                if (!b.empty())
                    b.pop();
            }
        }

        if (a.size() != b.size())
            return false;
        else
        {
            while (!a.empty() and !b.empty())
            {
                if (a.top() != b.top())
                    return false;

                a.pop();
                b.pop();
            }

            return true;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    Solution sol;
    // cout << sol.solved_using_brute_force(s, t);
    cout << sol.solve_using_better_solution(s, t);

    return 0;
}