#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void three_sum_smaller_two_pointer(vector<int> &arr, int t, int n)
    {

        int cnt = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {

                long long sum = arr[i] + arr[j] + arr[k];
                if (sum < t)
                {

                    cnt += (k - j);
                    j++;
                }
                else
                    k--;
            }
        }

        cout << cnt << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution sol;

    sol.three_sum_smaller_two_pointer(arr, t, n);

    return 0;
}