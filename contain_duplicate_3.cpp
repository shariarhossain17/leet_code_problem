#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void contain_duplicate_optimal(vector<int> &arr, int indexDiff, int valueDiff)
    {

        int n = arr.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {

            int need = abs(arr[i] - valueDiff);

            cout << need << endl;
            if (mp.find(arr[i] - valueDiff) != mp.end() and i - mp[arr[i] - valueDiff] <= indexDiff)
            {
                cout << "found";
                return;
            }

            mp[arr[i]] = i;
        }

        cout << "not found";
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
    {
        cin >> v[i];
    }

    int indexDiff, valueDiff;
    cin >> indexDiff >> valueDiff;

    Solution sol;
    sol.contain_duplicate_optimal(v, indexDiff, valueDiff);

    return 0;
}