#include <bits/stdc++.h>
using namespace std;

int find_duplicate_better(vector<int> &v, int n)
{

    int i = v[0], j = v[v[0]];
    while (i != j)
    {
        i = v[i];
        j = v[v[j]];
    }
    i = 0;
    while (i != j)
    {
        i = v[i];
        j = v[j];
    }
    return i;
}
int find_duplicate_optimal(vector<int> &v, int n)
{

    int xo = 0, xor_num = 0;

    for (int i = 0; i < n + 1; i++)
    {
        if ((i + 1) < n)
        {
            xor_num ^= (i + 1);
                }

        xo ^= v[i];
    }
    return xo ^ xor_num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n + 1);

    for (int i = 0; i < n + 1; i++)
        cin >> v[i];

    int better = find_duplicate_better(v, n);
    int optimal = find_duplicate_optimal(v, n);

    cout << optimal << endl;
    return 0;
}