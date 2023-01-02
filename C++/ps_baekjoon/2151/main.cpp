#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;
vector<vector<char>> board;
vector<vector<int>> vst;
vector<pair<int, int>> doors;
queue<tuple<int, int, int>> q;
map<char, int> direct
{
    {'L', 0},
    {'R', 1},
    {'D', 2},
    {'U', 3},
};
map<int, pair<int, int>> diff
{
    {0, {0, -1}},
    {1, {0, +1}},
    {2, {+1, 0}},
    {3, {-1, 0}},
};

pair<int, int> reflect(int d)
{
    if (d == direct['L'] || d == direct['R'])
        return {direct['U'], direct['D']};
    return {direct['L'], direct['R']};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 2, decltype(board)::value_type(n + 2));
    vst.resize(n + 2, decltype(vst)::value_type(n + 2, INF));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == '#')
                doors.emplace_back(i, j);
        }
    for (const auto& [ignore, direct_val] : direct)
        q.emplace(doors.front().first, doors.front().second, direct_val);
    vst[doors.front().first][doors.front().second] = 0;
    while (!q.empty())
    {
        auto [r, c, d] = q.front();
        auto [dr, dc] = diff[d];
        const auto& cnt = vst[r][c];
        q.pop();
        do
        {
            r += dr;
            c += dc;
            if (board[r][c] == '!' && vst[r][c] > cnt + 1)
            {
                vst[r][c] = cnt + 1;
                auto [d1, d2] = reflect(d);
                q.emplace(r, c, d1);
                q.emplace(r, c, d2);
            }
            if (board[r][c] == '#' && vst[r][c] > cnt + 1)
                vst[r][c] = cnt + 1;
        } while (board[r][c] != '*' && board[r][c] != '#' && board[r][c] != 0);
    }
    cout << vst[doors.back().first][doors.back().second] - 1;
    return 0;
}