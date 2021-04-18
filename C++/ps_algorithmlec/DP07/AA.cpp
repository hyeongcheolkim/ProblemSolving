// cpp algorithm ps number DP07

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> map(n + 2, vector<int>(n + 2, 100));
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 100));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (dp[i - 1][j] == 100 && dp[i][j - 1] == 100)
                dp[i][j] = map[i][j];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]) + map[i][j];
        }
    cout << dp[n][n];

    return 0;
}