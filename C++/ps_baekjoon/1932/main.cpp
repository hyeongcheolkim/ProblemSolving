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
    vector<vector<int>> map(n + 2, vector<int>(n + 2, 0));
    auto dp = map;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> map[i][j];
    dp[1][1] = map[1][1];
    for (int row = 2; row <= n; row++)
        for (int col = 1; col <= row; col++)
            dp[row][col] = map[row][col] + max(dp[row - 1][col - 1], dp[row - 1][col]);
    cout << *max_element(dp[n].begin(), dp[n].end());
    return 0;
}