#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;

    int rem = 0;

    int i = s1.size() - 1, j = s2.size() - 1;

    string ans = "";

    while (i >= 0 or j >= 0)
    {

        int sum = rem;

        if (i >= 0)
        {
            sum += s1[i] - 48;
        }
        if (j >= 0)
        {
            sum += s2[j] - 48;
        }

        ans += (sum % 2) + '0';
        rem = sum / 2;

        i--;
        j--;
    }

    if (rem > 0)
        ans += rem + '0';

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}