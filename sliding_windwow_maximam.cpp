#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void maxSlidingWindowBruteForce(vector<int> &nums, int k = 3)
    {
        int n = nums.size();

        vector<int> ans;

        for (int i = 0; i + k <= n; i++)
        {
            int mx = nums[i];

            for (int j = i + 1; j < i + k; j++)
            {

                mx = max(mx, nums[j]);
            }

            ans.push_back(mx);
        }

        for (auto i : ans)
            cout << i << " ";
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    Solution sol;

    sol.maxSlidingWindowBruteForce(v);

    return 0;
}