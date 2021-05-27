//baekjoon ps 9295

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string a, b, res = "";
    cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    int row = a.size();
    int col = b.size();
    while (dp[row][col] != 0)
    {
        if (dp[row][col] == dp[row][col - 1])
            col--;
        else if (dp[row][col] == dp[row - 1][col])
            row--;
        else if (dp[row][col - 1] == dp[row - 1][col])
        {
            res = b[col - 1] + res;
            col--;
            row--;
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
    if (dp[a.size()][b.size()] != 0)
        cout << res;
    return 0;
}