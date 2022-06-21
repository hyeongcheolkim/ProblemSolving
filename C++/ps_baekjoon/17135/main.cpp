#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, d, res;
vector<vector<int>> board, tmp_board;

bool board_empty()
{
    bool ret = false;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ret |= board[i][j];
    return !ret;
}

void move_enemy()
{
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            if (board[i][j] == 1)
            {
                board[i][j] = 0;
                int nr = i + 1;
                int nc = j;
                if (!(1 <= nr && nr <= n && 1 <= nc && nc <= m))
                    continue;
                board[nr][nc] = 1;
            }
}

void board_clear()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            board[i][j] = tmp_board[i][j];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> d;
    board.resize(n + 2, vector<int>(m + 3));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    tmp_board = board;
    board[n + 1][1] = board[n + 1][2] = board[n + 1][3] = 1;
    do
    {
        board_clear();
        int cnt = 0;
        while (!board_empty())
        {
            vector<pos> target;
            for (int i = 1; i <= m; ++i)
                if (board[n + 1][i])
                {
                    int dist = 0;
                    queue<pos> q, tq;
                    vector<vector<bool>> vst(n + 2, vector<bool>(m + 2));
                    vector<pos> tmp_target;
                    q.emplace(n + 1, i);
                    vst[n + 1][i] = true;
                    while (!q.empty() && dist < d)
                    {
                        while (!q.empty())
                        {
                            auto [r, c] = q.front();
                            q.pop();
                            for (int direction = 0; direction < size(dr); ++direction)
                            {
                                int nr = r + dr[direction];
                                int nc = c + dc[direction];
                                if (!(1 <= nr && nr <= n && 1 <= nc && nc <= m))
                                    continue;
                                if (board[nr][nc] == 1)
                                {
                                    tmp_target.emplace_back(nr, nc);
                                    continue;
                                }
                                vst[nr][nc] = true;
                                tq.emplace(nr, nc);
                            }
                        }
                        if (!tmp_target.empty())
                        {
                            sort(tmp_target.begin(), tmp_target.end(), [](pair<int, int> a, pair<int, int> b) {
                                return a.second < b.second;
                            });
                            target.push_back(tmp_target.front());
                            break;
                        }
                        ++dist;
                        q.swap(tq);
                    }
                }
            for (const auto& [r, c] : target)
                if (board[r][c] == 1)
                {
                    board[r][c] = 0;
                    ++cnt;
                }
            move_enemy();
        }
        res = max(res, cnt);
    } while (prev_permutation(board[n + 1].begin() + 1, board[n + 1].end() - 1));
    cout << res;
    return 0;
}