#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int n = nums.size();

        long long sum = 0;
        unordered_map<int, int> mp;

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (mp.count(sum - k))
                cnt += mp[sum - k];
            mp[sum]++;
        }

        cout << cnt << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> ar(n);

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    Solution sol;

    sol.subarraySum(ar, k);

    return 0;
}