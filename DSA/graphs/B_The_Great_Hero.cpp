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
    ll A, B;
    int N;
    cin >> A >> B >> N;

    vector<ll> a(N), b(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    for (int i = 0; i < N; ++i)
        cin >> b[i];

    ll max_attack = 0;
    vector<ll> damage(N);

    for (int i = 0; i < N; ++i)
    {
        ll hits_needed = (b[i] + A - 1) / A;
        damage[i] = hits_needed * a[i];
        max_attack = max(max_attack, a[i]);
    }

    ll total_damage = accumulate(damage.begin(), damage.end(), 0LL);

    if (B > total_damage - max_attack)
        Yes;
    else
        No;
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
