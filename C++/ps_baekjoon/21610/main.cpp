#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, dr[]{-1, -1, +1, +1}, dc[]{+1, -1, +1, -1};
int n, m, res;
vector<vector<int>> board;
vector<pair<int, int>> cloud;
map<int, pair<int, int>> diff{
    {1, {0, -1}},
    {2, {-1, -1}},
    {3, {-1, 0}},
    {4, {-1, +1}},
    {5, {0, +1}},
    {6, {+1, +1}},
    {7, {+1, 0}},
    {8, {+1, -1}},
};

pair<int, int> move_cloud(const pair<int, int>& pos, int direction, int s)
{
    auto [r, c] = pos;
    const auto& [dr, dc] = diff[direction];
    while (s--)
    {
        r += dr;
        if (r > n)
            r = 1;
        if (r < 1)
            r = n;
        c += dc;
        if (c > n)
            c = 1;
        if (c < 1)
            c = n;
    }
    return {r, c};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    cloud = vector<pair<int, int>>{{n, 1}, {n, 2}, {n - 1, 1}, {n - 1, 2}};
    while (m--)
    {
        int d, s;
        vector<pair<int, int>> copy_target;
        vector<vector<bool>> vst(n + 2, vector<bool>(n + 2));
        cin >> d >> s;
        for (auto& e : cloud)
            e = move_cloud(e, d, s);
        for (const auto& [r, c] : cloud)
        {
            ++board[r][c];
            copy_target.emplace_back(r, c);
            vst[r][c] = true;
        }
        cloud.clear();
        vector<tuple<int, int, int>> board_diff;
        for (const auto& [r, c] : copy_target)
        {
            int cnt = 0;
            for (int direction = 0; direction < 4; ++direction)
            {
                int nr = r + dr[direction];
                int nc = c + dc[direction];
                if (board[nr][nc] == OUT_OF_BOUND)
                    continue;
                cnt += (board[nr][nc] != 0);
            }
            board_diff.emplace_back(r, c, cnt);
        }
        for (const auto& [r, c, diff] : board_diff)
            board[r][c] += diff;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (board[i][j] >= 2 && !vst[i][j])
                {
                    cloud.emplace_back(i, j);
                    board[i][j] -= 2;
                }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            res += board[i][j];
    cout << res;
    return 0;
}