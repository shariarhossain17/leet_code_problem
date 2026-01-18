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
    string s;
    cin >> s;

    set<char> st;

    int i = 0, j = 0, ans = 0;

    while (j < n)
    {
        if (st.find(s[j]) == st.end())
        {
            st.insert(s[j]);
            ans = max(j - i + 1, ans);
            j++;
        }
        else
        {
            st.erase(s[i]);
            i++;
        }
    }

    cout << ans << endl;
}

void optimal()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> mp;

    int left = 0, j = 0, ans = 0;
    for (int right = 0; right < n; right++)
    {
        if (mp.count(s[right]) and mp[s[right]] >= left)
        {
            left = mp[s[right]] + 1;
        }
        mp[s[right]] = right;

        ans = max(ans, right - left + 1);
    }
    cout << ans << endl;
}
void better()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<char> hash(256, -1);

    int left = 0, j = 0, ans = 0;
    for (int right = 0; right < n; right++)
    {

        char c = s[right];
        if (hash[c] >= left)
        {
            left = hash[c] + 1;
        }
        hash[c] = right;

        ans = max(ans, right - left + 1);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        better();
    }
    return 0;
}