#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 5, EA = 7;
int res;
vector<vector<char>> board;
vector<pair<int, int>> candidate;

bool is_contain_4s(const vector<pair<int, int>>& target)
{
    int cnt = 0;
    for (const auto& [r, c] : target)
        if (board[r][c] == 'S')
            ++cnt;
    return cnt >= 4;
}

bool is_adjacent(const vector<pair<int, int>>& target)
{
    static constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
    vector<vector<int>> board(SIZE + 2, vector<int>(SIZE + 2, -1));
    vector<vector<bool>> vst(SIZE + 2, vector<bool>(SIZE + 2));
    queue<pair<int, int>> q;
    int cnt = 0;
    for (const auto& [r, c] : target)
        board[r][c] = 1;
    q.push(target.front());
    vst[target.front().first][target.front().second] = true;
    ++cnt;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (board[nr][nc] == -1)
                continue;
            if (vst[nr][nc])
                continue;
            if (board[nr][nc] != 1)
                continue;
            ++cnt;
            vst[nr][nc] = true;
            q.emplace(nr, nc);
        }
    }
    return cnt == EA;
}

void solve(int idx = 0)
{
    static vector<pair<int, int>> target;
    if (target.size() == EA)
    {
        if (is_contain_4s(target) && is_adjacent(target))
            ++res;
        return;
    }
    for (int i = idx; i < candidate.size(); ++i)
    {
        target.push_back(candidate[i]);
        solve(i + 1);
        target.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    board.resize(SIZE + 2, vector<char>(SIZE + 2));
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
        {
            cin >> board[i][j];
            candidate.emplace_back(i, j);
        }
    solve();
    cout << res;
    return 0;
}