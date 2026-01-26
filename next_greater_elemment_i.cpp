#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void solved_using_brute_force(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                bool f = false;
                if (nums1[i] == nums2[j])
                {
                    for (int k = j + 1; k < m; k++)
                    {
                        if (nums1[i] < nums2[k])
                        {
                            ans[i] = nums2[k];
                            f = true;
                            break;
                        }
                    }
                }

                if (f)
                {
                    break;
                }
            }
        }

        for (auto i : ans)
            cout << i << " ";
    }
    void solved_using_brute_better(vector<int> &nums1, vector<int> &nums2)
    {

        int m = nums2.size();

        vector<int> ans;

        stack<int> st;
        map<int, int> mp;

        for (int i = 0; i < m; i++)
        {

            while (!st.empty() and nums2[i] > st.top())
            {
                mp[st.top()] = nums2[i];
                st.pop();
            };

            st.push(nums2[i]);
        }

        while (!st.empty())
        {
            mp[st.top()] = -1;

            st.pop();
        }

        for (int i : nums1)
            ans.push_back(mp[i]);

        for (auto i : ans)
            cout << i << " ";
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> v(n), v2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    Solution sol;

    sol.solved_using_brute_better(v, v2);

    return 0;
}