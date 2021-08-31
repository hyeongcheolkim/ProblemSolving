#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e6;
int n, maxi, arr[mxN + 1], dp[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        const int &num = arr[i];
        dp[num] = dp[num - 1] + 1;
        maxi = max(maxi, dp[num]);
    }
    cout << n - maxi;
    return 0;
}