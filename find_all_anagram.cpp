#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void findAnagrams(string &s, string &p)
    {
        unordered_map<char, int> need;
        unordered_map<char, int> cur;

        for (auto i : p)
            need[i]++;
        vector<int> ans;
        int left = 0;
        int matched = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (need.count(ch))
            {
                cur[ch]++;
                if (cur[ch] == need[ch])
                    matched++;
            }

            if (i - left + 1 > p.size())
            {
                char leftChar = s[left];
                if (need.count(leftChar))
                {
                    if (cur[leftChar] == need[leftChar])
                        matched--;
                    cur[leftChar]--;
                }
                left++;
            }

            if (matched == need.size() && i - left + 1 == p.size())
                ans.push_back(left);
        }

        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    cin >> s >> p;

    Solution sol;

    sol.findAnagrams(s, p);
    return 0;
}