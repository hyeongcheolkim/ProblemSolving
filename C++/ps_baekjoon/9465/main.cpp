//baekjoon ps 9465

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(4, vector<int>(n + 2, 0));
        vector<vector<int>> dp(4, vector<int>(n + 2, 0));
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];
        dp[1][1] = arr[1][1];
        dp[2][1] = arr[2][1];
        dp[1][2] = arr[1][2]+arr[2][1];
        dp[2][2] = arr[2][2]+arr[1][1];
        for (int col = 3; col <= n; col++)
        {
            dp[1][col] = max({dp[2][col - 1], dp[1][col - 2], dp[2][col - 2]}) + arr[1][col];
            dp[2][col] = max({dp[1][col - 1], dp[1][col - 2], dp[1][col - 2]}) + arr[2][col];
        }
        cout << max(dp[1][n], dp[2][n]) << '\n';
    }
    return 0;
}