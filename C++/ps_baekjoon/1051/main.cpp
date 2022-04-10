#include <bits/stdc++.h>
using namespace std;
int n, m, maxi = 1;
vector<vector<char>> board;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<char>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int weight;
            for (weight = 0;; ++weight)
            {
                char val1 = board[i][j];
                char val2 = board[i + weight][j];
                char val3 = board[i][j + weight];
                char val4 = board[i + weight][j + weight];
                if (val1 == 0 || val2 == 0 || val3 == 0 || val4 == 0)
                    break;
                if (val1 == val2 && val2 == val3 && val3 == val4)
                    maxi = max(maxi, (int)pow(weight + 1, 2));
            }
        }
    cout << maxi;
    return 0;
}