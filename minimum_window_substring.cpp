#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> need, window;

        for (char c : t)
            need[c]++;

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                formed++;

            while (formed == required)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                char l = s[left];
                window[l]--;

                if (need.count(l) && window[l] < need[l])
                    formed--;

                left++;
            }
        }
        cout << s.substr(start, minLen);
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;

    cin >> s >> t;

    Solution sol;

    sol.minWindow(s, t);
    return 0;
}