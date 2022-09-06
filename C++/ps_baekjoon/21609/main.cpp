#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -5, EMPTY = -4, BLACK = -1, RAINBOW = 0, dr[]{0, 0, -1, +1}, dc[]{+1, -1, 0, 0};
int n, m, score;
vector<vector<int>> board;

void rotate_board()
{
    auto tmp = board;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            board[n - j + 1][i] = tmp[i][j];
}

void apply_gravity()
{
    for (int j = 1; j <= n; ++j)
        for (int i = n; i >= 1; --i)
        {
            if (board[i][j] == BLACK || board[i][j] == EMPTY)
                continue;
            int r = i;
            int c = j;
            while (board[r + 1][j] == EMPTY)
                ++r;
            swap(board[i][j], board[r][c]);
        }
}

map<int, vector<pair<int, int>>> get_target()
{
    map<int, vector<pair<int, int>>> ret;
    vector<vector<bool>> vst(n + 2, vector<bool>(n + 2));
    int maxi = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!vst[i][j] && board[i][j] > RAINBOW)
            {
                vector<vector<bool>> vst_rb(n + 2, vector<bool>(n + 2));
                map<int, vector<pair<int, int>>> target;
                queue<pair<int, int>> q;
                vst[i][j] = true;
                q.emplace(i, j);
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    if (board[r][c] == RAINBOW)
                        target[RAINBOW].emplace_back(r, c);
                    else
                        target[!RAINBOW].emplace_back(r, c);
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (board[nr][nc] < RAINBOW || vst[nr][nc])
                            continue;
                        if (board[nr][nc] == RAINBOW && vst_rb[nr][nc])
                            continue;
                        if (board[nr][nc] > RAINBOW && board[nr][nc] != board[i][j])
                            continue;
                        if (board[nr][nc] == RAINBOW)
                            vst_rb[nr][nc] = true;
                        else
                            vst[nr][nc] = true;
                        q.emplace(nr, nc);
                    }
                }
                if (int total_size = target[RAINBOW].size() + target[!RAINBOW].size(); total_size < 2)
                    continue;
                else if (maxi < total_size)
                {
                    maxi = total_size;
                    ret = target;
                }
                else if (maxi == total_size)
                {
                    if (ret[RAINBOW].size() == target[RAINBOW].size())
                    {
                        sort(ret[!RAINBOW].begin(), ret[!RAINBOW].end());
                        sort(target[!RAINBOW].begin(), target[!RAINBOW].end());
                        if (ret[!RAINBOW].front().first == target[!RAINBOW].front().first)
                        {
                            if (ret[!RAINBOW].front().second < target[!RAINBOW].front().second)
                                ret = target;
                        }
                        else if (ret[!RAINBOW].front().first < target[!RAINBOW].front().first)
                            ret = target;
                    }
                    else if (ret[RAINBOW].size() < target[RAINBOW].size())
                        ret = target;
                }
            }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    map<int, vector<pair<int, int>>> target;
    while (target = get_target(), target[RAINBOW].size() + target[!RAINBOW].size() != 0)
    {
        score += pow(target[RAINBOW].size() + target[!RAINBOW].size(), 2);
        for (const auto& [ignore, vec] : target)
            for (const auto& [row, col] : vec)
                board[row][col] = EMPTY;
        apply_gravity();
        rotate_board();
        apply_gravity();
    }
    cout << score;
    return 0;
}