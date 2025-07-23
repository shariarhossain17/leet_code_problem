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
    string x;
    cin >> x;

    string result = "";

    if (x[0] != '9')
    {
        for (char ch : x)
        {
            result += (char)('9' - ch + '0');
        }
    }
    else
    {
        string ans = "";
        int carry = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int digit_x = x[i] - '0';
            int digit_target = 1;

            int sub = digit_target - digit_x - carry;
            if (sub < 0)
            {
                sub += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            ans += (char)(sub + '0');
        }

        reverse(ans.begin(), ans.end());
        result = ans;
    }

    cout << result << '\n';
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