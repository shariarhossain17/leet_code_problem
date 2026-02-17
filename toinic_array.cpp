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
class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] >= nums[1])
        {
            return false;
        }
        int count = 1;
        for (int i = 2; i < n; i++)
        {
            if (nums[i - 1] == nums[i])
            {
                return false;
            }
            if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0)
            {
                count++;
            }
        }
        return count == 3;
    }
};
void solve()
{

    int n;
    cin >> n;

    Solution sol;

    vector<int> v(n);

    // take input

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sol.isTrionicDii(v);
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