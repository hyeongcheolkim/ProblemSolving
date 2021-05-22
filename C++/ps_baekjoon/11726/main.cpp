//baekjoon ps 11726

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int mod = 10007;
    int n;
    cin >> n;
    auto dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 2] % mod + dp[i - 1] % mod;
        dp[i] %= mod;
    }
    cout << dp[n];
    delete[] dp;
    return 0;
}