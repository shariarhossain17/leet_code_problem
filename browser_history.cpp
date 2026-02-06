#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
    vector<string> st;
    int cur = 0;

public:
    BrowserHistory(string homepage)
    {
        st.push_back(homepage);
    }

    void visit(string url)
    {
        while (st.size() > cur + 1)
            st.pop_back();

        st.push_back(url);
        cur++;
    }

    string back(int steps)
    {
        cur = max(0, cur - steps);
        return st[cur];
    }

    string forward(int steps)
    {
        cur = min((int)st.size() - 1, cur + steps);
        return st[cur];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BrowserHistory BrowserHistory("Leetcode");
    BrowserHistory.visit("google");
    BrowserHistory.visit("facebook");
    BrowserHistory.visit("youtube");
    BrowserHistory.back(1);
    BrowserHistory.back(1);
    BrowserHistory.forward(1);
    BrowserHistory.visit("linkedin");

    cout << BrowserHistory.back(2);

    return 0;
}