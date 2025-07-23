#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#define ll long long
#define newLine cout << "\n"
#define pb push_back
#define vi vector<int>
#define Yes cout << "YES\n"
#define No cout << "NO\n"
#define array_input_int(a, o, n) \
    for (int i = o; i < n; i++)  \
    {                            \
        cin >> (a[i]);           \
    }

void solve()
{
    int n;
    cin >> n;

    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.push(i);
    }

    vector<pair<int, int>> ans;

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        int avg = round((a + b) / 2.0);
        ans.push_back({a, b});
        st.push(avg);
    }

    cout << round((ans[ans.size() - 1].first + ans[ans.size() - 1].second) / 2.0) << endl;

    for (auto i : ans)
        cout << i.first << " " << i.second << endl;

    return;
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