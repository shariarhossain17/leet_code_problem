#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    if (x < 0)
        return 0;
    int copy = x;
    unsigned long long int y = 0;
    while (copy)
    {
        y *= 10;
        y += (copy % 10);
        copy /= 10;
    }
    bool state = x == y ? 1 : 0;

    cout << state << endl;

    return 0;
}