//baekjoon ps 10844

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr unsigned long long DIVISIOR = 1000000000;
    int n;
    unsigned long long sum = 0;
    cin >> n;
    vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(11, 0));
    dp[1][0] = 0;
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= 9; j++)
        {
            if(j-1>=0 && j+1<=9)
                dp[i][j] += (dp[i - 1][j - 1] +  dp[i - 1][j + 1])%DIVISIOR;
            else if(j-1<0)
                dp[i][j] += dp[i - 1][j + 1];
            else
                dp[i][j] += dp[i - 1][j - 1];
        }
    for (int i = 0; i <= 9;i++)
        sum = (sum+dp[n][i])%DIVISIOR;
    cout << sum;

    return 0;
}