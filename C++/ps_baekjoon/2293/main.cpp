//baekjoon ps 2293

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), dp(k + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0] = 1;
    for (const auto &cost : arr)
        for (int i = cost; i <= k; i++)
            dp[i] += dp[i - cost];
    cout << dp[k];
    return 0;
}