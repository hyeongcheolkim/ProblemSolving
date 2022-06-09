#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, maxi_len;
vector<int> arr, dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n + 1); dp.resize(n + 1);
    arr[0] = INF;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxi_len = max(maxi_len, dp[i]);
            }
    cout << n - maxi_len;
    return 0;
}