#include <bits/stdc++.h>
using namespace std;
using node = tuple<int, int, int>;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> board(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    priority_queue<node> pq;
    for (int i = 1; i <= n; ++i)
        pq.emplace(board[n][i], n, i);
    while (--n)
    {
        auto [value, row, col] = pq.top();
        pq.pop();
        if (row == 1)
            continue;
        pq.emplace(board[row - 1][col], row - 1, col);
    }
    cout << get<0>(pq.top());
    return 0;
}