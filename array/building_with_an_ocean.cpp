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

// void solve()
// {
//     int n;
//     cin >> n;

//     vi v(n);
//     array_input_int(v, 0, n);

//     vi ans;

//     stack<int> st;
//     st.push(v[n - 1]);

//     ans.push_back(n - 1);

//     for (int i = n - 2; i >= 0; i--)
//     {
//         int val = st.top();
//         if (v[i] > val)
//         {
//             st.pop();
//             st.push(v[i]);
//             ans.push_back(i);
//         }
//     }

//     reverse(ans.begin(), ans.end());

//     for (auto i : ans)
//         cout << i << " ";
//     newLine;
// }
// reduce space complexity
void solve()
{
    int n;
    cin >> n;

    vi v(n);
    array_input_int(v, 0, n);

    vi ans;

    // stack<int> st;
    // st.push(v[n - 1]);

    int val = v[n - 1];

    ans.push_back(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {

        if (v[i] > val)
        {
            val = v[i];

            ans.push_back(i);
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i << " ";
    newLine;
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