#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {

        int n = arr.size();
        unordered_map<int, int> mp;

        mp[0] = -1;

        int mx_len = 0;
        int cur_sum = 0;

        for (int i = 0; i < n; i++)
        {

            cur_sum += arr[i];

            if (mp.count(cur_sum - k))
            {
                mx_len = max(mx_len, i - mp[cur_sum - k]);
            }

            if (mp.find(cur_sum) == mp.end())
                mp[cur_sum] = i;
        }
        return mx_len;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution sol;

    sol.longestSubarray(arr, k);
    return 0;
}