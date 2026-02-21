#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> ar(n + 1, 0);

        for (int i = 0; i < n; i++)
            ar[nums[i]]++;

        vector<int> ans;

        for (int i = 1; i <= n; i++)
            if (ar[i] == 0)
                ans.push_back(i);

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

    vector<int> ar(n, 0);

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    Solution sol;
    sol.findDisappearedNumbers(ar);
    return 0;
}