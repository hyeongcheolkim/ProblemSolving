#include <bits/stdc++.h>
using namespace std;

constexpr long long dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
long long n, m, mini, maxi;
vector<vector<char>> board;
vector<vector<long long>> vst;
vector<long long> start, end;
vector<pair<long long, long long>> start_pos, end_pos;
queue<pair<long long, long long>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, decltype(board)::value_type(m + 2));
    vst.resize(n + 2, decltype(vst)::value_type(m + 2, -1));
    for (long long i = 1; i <= n; ++i)
        for (long long j = 1; j <= m; ++j)
            cin >> board[i][j];
    vst[1][1] = 0;
    q.emplace(1, 1);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        const auto& cost = vst[r][c];
        bool flag = true;
        q.pop();
        if (r == n && c == m)
            continue;
        for (long long direction = 0; direction < 4; ++direction)
        {
            long long nr = r + dr[direction];
            long long nc = c + dc[direction];
            if (board[nr][nc] == 0 || vst[nr][nc] != -1 || board[nr][nc] == '#')
                continue;
            q.emplace(nr, nc);
            vst[nr][nc] = cost + 1;
            flag = false;
        }
        if (flag)
            start_pos.emplace_back(r, c);
    }
    mini = vst[n][m];
    for (const auto& [r, c] : start_pos)
        maxi += 2 * vst[r][c];

    vst.assign(n + 2, decltype(vst)::value_type(m + 2, -1));
    vst[n][m] = 0;
    q.emplace(n, m);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        const auto& cost = vst[r][c];
        bool flag = true;
        q.pop();
        if (r == 1 && c == 1)
            continue;
        for (long long direction = 0; direction < 4; ++direction)
        {
            long long nr = r + dr[direction];
            long long nc = c + dc[direction];
            if (board[nr][nc] == 0 || vst[nr][nc] != -1 || board[nr][nc] == '#')
                continue;
            q.emplace(nr, nc);
            vst[nr][nc] = cost + 1;
            flag = false;
        }
        if (flag)
            end_pos.emplace_back(r, c);
    }
    for (const auto& [r, c] : end_pos)
        maxi += 2 * vst[r][c];
    maxi += mini;
    cout << mini << ' ' << maxi;
    return 0;
}