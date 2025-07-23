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

bool dfs(vector<int> graph[], int col, vector<int> &color, int node)
{
    color[node] = col;

    for (auto it : graph[node])
    {
        if (color[it] != -1)
        {
            dfs(graph, !col, color, node);
        }
        else if (col == color[it])
            return false;
    }
}
void solve()
{
    int n, v;
    cin >> n >> v;

    vector<int> graph[n];

    for (int i = 0; i < v; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n, -1);
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        if (!dfs(graph, 0, color, i))
        {
            cout << "false";
            return;
        }
    }

    cout << "true";
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