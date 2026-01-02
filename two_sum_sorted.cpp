#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> twoSum(vector<int> &arr, int t)
    {
        int n = arr.size();

        int l = 0, r = n - 1, sum = 0;

        while (l < r)
        {
            sum = arr[l] + arr[r];

            if (sum == t)
                break;
            else if (sum < t)
                l++;
            else
                r--;
        }

        return {l, r};
    }

    vector<int> usingHash(vector<int> &ar, int t)
    {
        int n = ar.size();

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int need = t - ar[i];

            if (mp.find(need) != mp.end())
            {
                return {mp[need], i + 1};
            };

            mp[ar[i]] = i + 1;
        }
    }
}

;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int n, t;
    cin >> n >> t;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> ans = sol.twoSum(v, t);

    vector<int> ans2 = sol.usingHash(v, t);

    cout << ans2[0] << ans2[1] << endl;

    return 0;
}