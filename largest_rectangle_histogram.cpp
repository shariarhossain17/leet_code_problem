#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void largestRectangleAreaBruteForce(vector<int> &heights)
    {

        int n = heights.size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int min_w = heights[i];

            ans = max(min_w, ans);

            for (int j = i + 1; j < n; j++)
            {
                min_w = min(heights[j], min_w);

                ans = max(ans, min_w * (j - i + 1));
            }
        }

        cout << ans << endl;
    }

    void optimal_solution(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int height = heights[st.top()];

                cout << height << endl;
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                {
                    width = i - st.top() - 1;
                }

                ans = max(ans, height * width);
            }
            st.push(i);
        }

        while (!st.empty())
        {
            int height = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = n;
            else
                width = n - st.top() - 1;

            ans = max(ans, height * width);
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
    sol.optimal_solution(v);
    return 0;
}