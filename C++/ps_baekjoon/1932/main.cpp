//baekjoon ps 1932

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1, vector<int>(n + 1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n * (n + 1) / 2; i++)
    {
        static int cnt = 0;
        static int row = 1;
        static int col = 1;
        cin >> tree[row][col++];
        cnt++;
        if (cnt == row * (row + 1) / 2)
        {
            row++;
            col = 1;
        }
    }
    dp[1][1] = tree[1][1];
    dp[2][1] = dp[1][1] + tree[2][1];
    dp[2][2] = dp[1][1] + tree[2][2];
    for (int row = 3; row <= n; row++)
        for (int col = 1; col <= row; col++)
        {
            if (col == 1)
                dp[row][col] = tree[row][col] + dp[row - 1][col];
            else if (col == row)
                dp[row][col] = tree[row][col] + dp[row - 1][col - 1];
            else
                dp[row][col] = tree[row][col] + max(dp[row - 1][col], dp[row - 1][col - 1]);
        }
    cout << *max_element(dp[n].begin()+1, dp[n].begin() + n + 1);
    return 0;
}