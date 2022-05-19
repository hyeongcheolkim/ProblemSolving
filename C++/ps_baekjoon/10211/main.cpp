#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxi = -INF;
        cin >> n;
        vector<int> arr(n + 1), acc(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            acc[i] = acc[i - 1] + arr[i];
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; ++j)
            {
                int sum = acc[i] - acc[j];
                maxi = max(maxi, sum);
            }
        cout << maxi << '\n';
    }
    return 0;
}