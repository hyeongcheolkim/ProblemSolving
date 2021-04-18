// cpp algorithm ps number DP08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recursion(const int &row, const int& column, int sum, const vector<vector<int>> &map,vector<vector<int>> &dp )
{
    if(dp[row][column]==100000)
        dp[row][column] = sum;
    else if(dp[row][column]<sum)
        return 100000000;
    else if(dp[row][column]>sum)
        dp[row][column] = sum;

    if(map[row][column]==100000)
        return sum;
    if(row==1 && column==1)
        return sum;
    return min(recursion(row - 1, column,sum+map[row-1][column], map,dp), recursion(row, column - 1,sum+map[row][column-1], map,dp));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> map(n + 2, vector<int>(n + 2, 100000));
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 100000));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    cout << recursion(n, n, map[n][n], map, dp);
    return 0;
}