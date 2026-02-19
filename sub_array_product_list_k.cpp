#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {

        int n = nums.size();

        int cnt = 0;
        int product = 1;

        for (int i = 0, j = 0; j < n; j++)
        {
            product *= nums[j];

            while (i <= j && product >= k)
            {
                product /= nums[i];
                i++;
            }

            cnt += (j - i + 1);
        }

        return cnt;
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

    Solution Sol;

    cout << Sol.numSubarrayProductLessThanK(ar, k) << endl;

    return 0;
}