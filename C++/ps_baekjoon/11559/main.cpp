#include <bits/stdc++.h>
using namespace std;

constexpr int mxR = 12, mxC = 6, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
vector<vector<char>> board;
vector<vector<bool>> vst;
int res;

vector<pair<int, int>> pop(int row, int col)
{
    char color = board[row][col];
    queue<pair<int, int>> q;
    vector<pair<int, int>> pop_target{{row, col}};
    vst[row][col] = true;
    q.emplace(row, col);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (vst[nr][nc] || board[nr][nc] != color)
                continue;
            vst[nr][nc] = true;
            q.emplace(nr, nc);
            pop_target.emplace_back(nr, nc);
        }
    }
    if (pop_target.size() >= 4)
        return move(pop_target);
    else
        return vector<pair<int, int>>{};
}

void gravity()
{
    for (int c = 1; c <= mxC; ++c)
        for (int r = mxR; r >= 1; --r)
            if (board[r][c] != '.')
            {
                int row = r;
                while (board[row + 1][c] == '.')
                    ++row;
                swap(board[row][c], board[r][c]);
            }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    board.resize(mxR + 2, vector<char>(mxC + 2));
    for (int i = 1; i <= mxR; ++i)
        for (int j = 1; j <= mxC; ++j)
            cin >> board[i][j];
    while ([&] {
        vector<vector<pair<int, int>>> vec_pop_target;
        vst.assign(mxR + 2, vector<bool>(mxC + 2, false));
        for (int i = 1; i <= mxR; ++i)
            for (int j = 1; j <= mxC; ++j)
                if (board[i][j] != '.' && !vst[i][j])
                    if (auto&& ret = pop(i, j); !ret.empty())
                        vec_pop_target.push_back(ret);
        if (!vec_pop_target.empty())
        {
            ++res;
            for (const auto& pop_target : vec_pop_target)
                for (const auto& [r, c] : pop_target)
                    board[r][c] = '.';
            gravity();
            return true;
        }
        else
            return false;
    }());
    cout << res;
    return 0;
}