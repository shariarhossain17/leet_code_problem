#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        int n = s.size();

        int mx_fq = 0;
        int mx_len = 0;

        vector<int> freq(26, 0);
        int j = 0;

        for (int i = 0; i < n; i++)
        {

            freq[s[i] - 'A']++;
            mx_fq = max(mx_fq, freq[s[i] - 'A']);

            while ((i - j + 1) - mx_fq > k)
            {

                freq[s[j] - 'A']--;
                j++;
            }

            mx_len = max(mx_len, i - j + 1);
        }

        cout << mx_len;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    string s;
    cin >> s;

    Solution sol;
    sol.characterReplacement(s, k);
    return 0;
}