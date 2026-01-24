#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve_using_brute_force(vector<int> &v)
    {
        int n = v.size();

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                if (v[i] < v[j])
                {
                    ans[i] = j - i;
                    break;
                }
            }
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
    sol.solve_using_brute_force(v);

    return 0;
}