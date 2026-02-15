#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void lengthOfLongestSubstring(string s)
    {

        int n = s.size(), left = 0, ans = 0;

        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;

            while (mp[s[i]] > 1)
            {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, i - left + 1);
        }
        cout << ans << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    Solution sol;
    sol.lengthOfLongestSubstring(s);
    return 0;
}