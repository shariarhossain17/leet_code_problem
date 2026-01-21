#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solved_using_brute_force(string &s)
    {

        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    string s;
    cin >> s;
    sol.solved_using_brute_force(s);

    return 0;
}