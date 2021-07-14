//baekjoon ps 17404

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

enum RGB
{
    R = 0,
    G = 1,
    B = 2,
};

int main()
{
    ios_base::sync_with_stdio(false);
    int res = numeric_limits<int>::max();
    int n;
    cin >> n;
    vector<vector<int>> rgb(n + 1, vector<int>(3));
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        rgb[i][R] = r;
        rgb[i][G] = g;
        rgb[i][B] = b;
    }
    for (int first = RGB::R; first <= RGB::B; first++)
    {
        for (int i = RGB::R; i <= RGB::B; i++)
            if (first == i)
                dp[1][i] = rgb[1][i];
            else
                dp[1][i] = numeric_limits<int>::max() / 3;
        for (int i = 2; i <= n; i++)
        {
            dp[i][R] = rgb[i][R] + min(dp[i - 1][G], dp[i - 1][B]);
            dp[i][G] = rgb[i][G] + min(dp[i - 1][R], dp[i - 1][B]);
            dp[i][B] = rgb[i][B] + min(dp[i - 1][R], dp[i - 1][G]);
        }
        for (int i = RGB::R; i <= RGB::B; i++)
            if (first != i)
                res = min(res, dp[n][i]);
    }
    cout << res;
    return 0;
}