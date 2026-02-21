#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDuplicatesBetter(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<int> ans;
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                ans.push_back(nums[i]);
        }

        for (auto i : ans)
            cout << i << " ";
    }
    vector<int> findDuplicateOptimal(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        vector<int> frq(n + 1, 0);

        for (int i = 0; i < n; i++)
        {

            frq[nums[i]]++;

            if (frq[nums[i]] >= 2)
                ans.push_back(nums[i]);
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

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution sol;

    sol.findDuplicateOptimal(arr);

    return 0;
}