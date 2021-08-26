#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e3;
int board[mxN + 1][mxN + 1];
int n, m, res = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char temp;
            cin >> temp;
            board[i][j] = temp - '0';
            if (board[i][j] == 1)
            {
                board[i][j] += min({board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]});
                res = max(res, board[i][j]);
            }
        }
    cout << pow(res, 2);
    return 0;
}