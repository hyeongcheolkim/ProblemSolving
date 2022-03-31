#include <bits/stdc++.h>
using namespace std;

int n, maxi;
vector<int> arr, dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (const auto& e : {&arr, &dp})
        e->resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
    return 0;
}