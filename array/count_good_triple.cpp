#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int countcountGoodTripletsTriplates(vector<int> &arr, int a, int b, int c)
    {
        int n = arr.size(), cnt = 0;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int x1 = abs(arr[i] - arr[j]);
                    int x2 = abs(arr[j] - arr[k]);
                    int x3 = abs(arr[k] - arr[i]);

                    if (x1 <= a and x2 <= b and x3 <= c)
                    {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }

public:
    int countGoodTriplesOptimize(vector<int> &arr, int a, int b, int c)
    {

           int n = arr.size(), cnt = 0;

        for (int i = 0; i < n - 1; i++)
        {

            for (int k = i + 2; k < n; k++)
            {

                cout << arr[i] << " " << arr[i + 1] << " " << arr[k] << endl;
                // int x1 = abs(arr[i] - arr[i + 1]);
                // int x2 = abs(arr[i + 1] - arr[k]);
                // int x3 = abs(arr[k] - arr[i]);

                // if (x1 <= a and x2 <= b and x3 <= c)
                // {
                //     cnt++;
                // }
            }
        }

        return cnt;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solution sl;

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = sl.countGoodTriplesOptimize(arr, a, b, c);

    cout << ans << endl;

    return 0;
}