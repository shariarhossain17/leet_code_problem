#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int mid = st.top();
                st.pop();

                if (st.empty())
                    break;

                int left = st.top();
                int width = i - left - 1;
                int boundedHeight = min(height[left], height[i]) - height[mid];

                ans += width * boundedHeight;
            }
            st.push(i);
        }

        cout << ans << endl;
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
    sol.trap(v);

    return 0;
}