#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSumBruteForce(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        st.insert({arr[i], arr[j], arr[k]});
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
    vector<vector<int>> threeSumOptimize(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;

            while (j < k)
            {

                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0)
                {
                    st.insert({arr[i], arr[j], arr[k]});
                    j++;
                }
                else if (sum > 0)
                    k--;
                else
                    j++;
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
    vector<vector<int>> threeSumOptimal(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {

            if (i > 0 and arr[i - 1] == arr[i])
                continue;
            int j = i + 1, k = n - 1;

            while (j < k)
            {

                int sum = arr[i] + arr[j] + arr[k];

                if (sum > 0)
                    k--;
                else if (sum < 0)
                    j++;
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k]});

                    while (j < k and arr[j] == arr[j + 1])
                    {
                        j++;
                    }
                    while (k > j and arr[k] == arr[k - 1])
                    {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> result = sol.threeSumOptimize(v, n);

    for (auto &triplet : result)
    {
        for (auto x : triplet)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
