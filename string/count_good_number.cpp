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

const int mod = 1e9 + 7;
void solve()
{

    ll n;
    cin >> n;

    long long ans = 1;

    for (long long i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            ans = (ans * 5) % mod;
        else
            ans = (ans * 4) % mod;
    }

    cout << ans << endl;
}
ll modpow(ll base, ll exp, ll mod)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void optimize_solution()
{
    ll n;
    cin >> n;
    ll even = modpow(5, n / 2, mod);
    ll odd = modpow(4, n / 2, mod);

    cout << (even * odd) % mod << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        optimize_solution();
    }
    return 0;
}