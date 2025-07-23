#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define newLine cout << "\n"
#define pb push_back
#define vi vector<int>
#define Yes cout << "YES\n"
#define No cout << "NO\n"

bool cmp(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int i = 0, j = 0;
    while (i < s1.size())
    {
        if (j < s2.size() && s1[i] == s2[j])
        {
            j++;
        }
        i++;
    }
    return j == s2.size();
}

void solve()
{
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (cmp(v[i], v[j]) && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
