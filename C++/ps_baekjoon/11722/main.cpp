#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 1;
    cin >> n;
    vector<int> arr(n + 1), dp(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }
    cout << res;
    return 0;
}