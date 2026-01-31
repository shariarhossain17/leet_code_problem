#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void solve_using_better(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;

        vector<int> res(n, -1);

        for (int i = 0; i < 2 * n; i++)
        {

            while (!st.empty() and nums[st.top()] < nums[i % n])
            {

                            res[st.top()] = nums[i % n];
                st.pop();
            }

            if (i < n)
                st.push(i);
        }

        for (auto i : res)
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

    sol.solve_using_better(v);

    return 0;
}