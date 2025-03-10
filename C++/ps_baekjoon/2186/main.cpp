#include <bits/stdc++.h>
using namespace std;

int n, m, k, result = 0;
vector<vector<char>> board;
string word;
vector<vector<vector<int>>> cache;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};

int solve(int r, int c, int d)
{
    int &ret = cache[r][c][d];
    if (ret != -1)
        return ret;
    ret = 0;
    if (word[d] != board[r][c])
        return ret = 0;
    if (d == word.length() - 1)
        return ret = 1;
    for (int diff = 1; diff <= k; ++diff)
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction] * diff;
            int nc = c + dc[direction] * diff;
            if (!(0 <= nr && nr < n && 0 <= nc && nc < m))
                continue;
            if (board[nr][nc] != word[d + 1])
                continue;
            ret += solve(nr, nc, d + 1);
        }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    board.resize(n, vector<char>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    cin >> word;
    cache.resize(n, vector<vector<int>>(m, vector<int>(word.length(), -1)));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result += solve(i, j, 0);
    cout << result;
    return 0;
}