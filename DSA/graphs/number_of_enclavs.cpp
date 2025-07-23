#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#define ll long long
#define newLine cout << "\n"
#define pb push_back
#define vi vector<int>
#define Yes cout << "YES\n"
#define No cout << "NO\n"
#define array_input_int(a, o, n) \
    for (int i = o; i < n; i++)  \
    {                            \
        cin >> (a[i]);           \
    }

void solve()
{

    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    queue<pair<int, int>> q;

    vector<vector<bool>> vis(m, vector(n, false));

    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == '1')
        {
            vis[i][0] = true;
            q.push({0, i});
        }
        if (grid[i][n - 1] == '1')
        {
            vis[i][n - 1] = true;
            q.push({i, n - 1});
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == '1')
        {
            vis[0][i] = true;
            q.push({0, i});
        }
        if (grid[m - 1][i] == '1')
        {
            vis[n - 1][i] = true;
            q.push({m - 1, i});
        }
    }

    // int rowD[4] = {1, -1, 0, 0};
    // int colD[4] = {0, 0, 1, -1};

    // while (!q.empty())
    // {
    //     int row = q.front().first;
    //     int col = q.front().second;
    //     q.pop();

    //     for (int i = 0; i < 4; i++)
    //     {
    //         int r = row + rowD[i];
    //         int c = col + colD[i];

    //         if ((r >= 0 and r < m) and (c >= 0 and c < n) and grid[r][c] == '1' and !vis[r][c])
    //         {
    //             q.push({r, c});
    //             vis[r][c] = true;
    //         }
    //     }
    // }

    // int cnt = 0;

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (grid[i][j] == '1' and !vis[i][j])
    //             cnt++;
    //     }
    // }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}