#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int find_maxi_mam_area(vector<int> &arr)
    {

        int n = arr.size();

        int ans = 0;

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] > arr[i])
            {
                int h = st.top();
                st.pop();

                int w;

                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                ans = max(w * h, ans);
            }

            st.push(i);
        }

        while (!st.empty())
        {
            int h = arr[st.top()];
            st.pop();

            int w;

            if (st.empty())
                w = n;
            else
                w = n - st.top() - 1;

            ans = max(w * h, ans);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            ans = max(ans, find_maxi_mam_area(height));
        }

        cout << ans << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    Solution sol;

    sol.maximalRectangle(v);
    return 0;
}