#include <bits/stdc++.h>
using namespace std;

vector<int> plus_one(vector<int> &nums)
{
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < 9)
        {
            nums[i]++;
            return nums;
        }
        nums[i] = 0;
    }

    nums.insert(nums.begin(), 1);
    return nums;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n + 1);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = plus_one(nums);

    return 0;
}