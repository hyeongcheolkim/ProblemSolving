#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{+1, 0, -1, 0}, dc[]{0, +1, 0, -1};
int n, num;
pair<int, int> pos;
vector<vector<int>> board;
vector<pair<int, int>> cache;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> num;
    board.resize(n + 1, vector<int>(n + 1));
    cache.resize(n * n + 1);
    pos = {n / 2 + 1, n / 2 + 1};
    for (int i = 1; i <= n; i += 2)
    {
        auto [r, c] = pos;
        int idx = i * i;
        int step = (i - 1);
        board[r][c] = idx;
        cache[idx] = {r, c};
        for (int direction = 0; direction < 4; ++direction)
        {
            for (int j = 0; j < step; ++j)
            {
                r += dr[direction];
                c += dc[direction];
                if (board[r][c] != 0)
                    continue;
                board[r][c] = --idx;
                cache[idx] = {r, c};
            }
        }
        --pos.first;
        --pos.second;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << cache[num].first << ' ' << cache[num].second;
    return 0;
}