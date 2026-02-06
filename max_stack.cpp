#include <bits/stdc++.h>
using namespace std;

class MaxStack
{

    vector<int> st;
    vector<int> mx_st;

public:
    MaxStack()
    {
        // Write your code here.
    }

    void specialPush(int value)
    {
        st.push_back(value);

        if (mx_st.empty() || mx_st.back() <= value)
            mx_st.push_back(value);
    }
    int specialPop()
    {
        int val = st.back();

        st.pop_back();

        if (val == mx_st.back())
            mx_st.pop_back();

        return val;
    }

    int specialTop()
    {
        return st.back();
    }

    int specialMax()
    {
        return mx_st.back();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    MaxStack MaxStack;

    MaxStack.specialPush(10);
    MaxStack.specialPush(20);

    MaxStack.specialPush(5);

    cout << MaxStack.specialTop() << endl;
    cout << MaxStack.specialMax();

    return 0;
}