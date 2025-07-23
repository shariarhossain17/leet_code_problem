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

    int n;
    cin >> n;

    string beginWord, endWord;
    vector<string> wordList(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wordList[i];
    }

    cin >> beginWord >> endWord;

    set<string> st;
    st.insert(wordList.begin(), wordList.end());

    queue<pair<string, int>> q;

    q.push({beginWord, 1});

    while (!q.empty())
    {
        string w = q.front().first;
        int lvl = q.front().second;

        q.pop();

        if (w == endWord)
        {
            cout << lvl;
            break;
        }

        for (int i = 0; i < w.size(); i++)
        {

            char cur = w[i];

            for (char j = 'a'; j <= 'z'; j++)
            {
                w[i] = j;

                if (st.find(w) != st.end())
                {
                    q.push({w, lvl + 1});
                    st.erase(w);
                }
            }

            w[i] = cur;
        }
    }
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