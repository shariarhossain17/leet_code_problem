#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define newLine cout << "\n"
#define pb push_back
#define vi vector<int>
#define Yes cout << "YES\n"
#define No cout << "NO\n"

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && dp1[j] + 1 > dp1[i])
            {
                dp1[i] = dp1[j] + 1;
            }
        }
        ans = max(ans, dp1[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (v[i] > v[j] && dp2[j] + 1 > dp2[i])
            {
                dp2[i] = dp2[j] + 1;
            }
        }
        ans = max(ans, dp2[i]);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i], dp2[i] - 1);
    }

    cout << maxi << endl;
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
