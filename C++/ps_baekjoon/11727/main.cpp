//baekjoon ps 11727

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int mode = 10007;
    int n;
    cin >> n;
    auto dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 2] * 2)%mode + dp[i - 1]%mode;
        dp[i] %= mode;
    }
    cout << dp[n];
    delete[] dp;
    return 0;
}