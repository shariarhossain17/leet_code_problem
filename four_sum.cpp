#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void four_sum_brute_force(vector<int> &arr, int target)
    {
        set<vector<int>> st;

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if (arr[i] + arr[j] + arr[k] + arr[l])
                        {
                            st.insert({arr[i], arr[j], arr[k], arr[l]});
                        }
                    }
                }
            }
        }

        for (auto i : st)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }

    void four_sum_optimal(vector<int> &arr, int t)
    {

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {

            if (i > 0 and arr[i] == arr[i + 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {

                map<int, int> mp;
                for (int k = j + 1; k < n; k++)
                {
                    int need = t - (arr[i] + arr[j] + arr[k]);

                    if (mp.find(need) != mp.end())
                    {
                        cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << mp[need] << endl;
                    }

                    mp[arr[k]] = arr[k];
                }
            }
        }
    }
    void four_sum_better(vector<int> &arr, int t)
    {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {

            if (i > 0 and arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 and arr[j] == arr[j - 1])
                    continue;

                int l = j + 1, r = n - 1;

                while (l < r)
                {
                    long long sum = arr[i] + arr[j] + arr[l] + arr[r];

                    if (sum == t)
                    {
                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                        l++;
                        r--;
                        while (l < r and arr[l] == arr[l - 1])
                        {
                            l++;
                        }
                        while (l < r and arr[r] == arr[r + 1])
                        {
                            r--;
                        }
                    }
                    else if (sum > t)
                        r--;
                    else
                        l++;
                }
            }
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // sol.four_sum_brute_force(arr, t);
    sol.four_sum_optimal(arr, t);

    return 0;
}