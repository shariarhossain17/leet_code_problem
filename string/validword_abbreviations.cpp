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

    string a, b;
    cin >> a >> b;

    int i = -0, j = 0;

    // if (a.size() < b.size())
    // {
    //     cout << "false";
    //     return;
    // }

    while (i < a.size())
    {
        string c = "0";

        if (b[j] > '0' and b[j] <= '9')
        {
            c += b[j];
            j++;
        }
        else if (a[i + stoi(c) - 1] == b[j])
        {
            i++;
            j++;
            c = "0";
        }
        else
        {
            cout << "false";
            return;
        }
    }

    cout << "True";
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