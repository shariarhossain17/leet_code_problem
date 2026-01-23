#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void remove_duplicate_better(string &s)
    {
        int n = s.size();

        string ans = "";

        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || ans.back() != s[i])
                ans += s[i];
            else
            {

                string tmp = ans;
                tmp.erase(tmp.length() - 1);

                ans = tmp;
            }
        }

        cout << ans << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    Solution Sol;
    Sol.remove_duplicate_better(s);
    return 0;
}