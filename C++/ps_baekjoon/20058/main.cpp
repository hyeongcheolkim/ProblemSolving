#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, dr[]{+1, -1, 0, 0}, dc[]{0, 0, +1, -1};
int n, k, SIZE;
vector<vector<int>> board;

void rotate_mat(int lv, int row_lt = 1, int row_rt = SIZE, int col_lt = 1, int col_rt = SIZE)
{
    if (lv == n)
    {
        int row_size = row_rt - row_lt + 1;
        int col_size = col_rt - col_lt + 1;
        vector<vector<int>> tmp(row_size, vector<int>(col_size));
        for (int row = row_lt; row <= row_rt; ++row)
            for (int col = col_lt; col <= col_rt; ++col)
                tmp[col - col_lt][row_rt - row] = board[row][col];
        for (int row = row_lt; row <= row_rt; ++row)
            for (int col = col_lt; col <= col_rt; ++col)
                board[row][col] = tmp[row - row_lt][col - col_lt];
        return;
    }
    int row_mid = (row_lt + row_rt) / 2;
    int col_mid = (col_lt + col_rt) / 2;
    rotate_mat(lv + 1, row_lt, row_mid, col_lt, col_mid);
    rotate_mat(lv + 1, row_lt, row_mid, col_mid + 1, col_rt);
    rotate_mat(lv + 1, row_mid + 1, row_rt, col_lt, col_mid);
    rotate_mat(lv + 1, row_mid + 1, row_rt, col_mid + 1, col_rt);
}

void melt_ice()
{
    vector<pair<int, int>> melt_target;
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            if (board[i][j])
            {
                int cnt = 0;
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = i + dr[direction];
                    int nc = j + dc[direction];
                    if (board[nr][nc] > 0)
                        ++cnt;
                }
                if (!(cnt >= 3))
                    melt_target.emplace_back(i, j);
            }
    for (const auto& [r, c] : melt_target)
        --board[r][c];
}

int maxi_iceberg()
{
    int ret = 0;
    vector<vector<bool>> vst(SIZE + 2, vector<bool>(SIZE + 2));
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            if (!vst[i][j] && board[i][j])
            {
                queue<pair<int, int>> q;
                vst[i][j] = true;
                q.emplace(i, j);
                int ice = 1;
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (vst[nr][nc] || board[nr][nc] == OUT_OF_BOUND || board[nr][nc] == 0)
                            continue;
                        vst[nr][nc] = true;
                        q.emplace(nr, nc);
                        ++ice;
                    }
                }
                ret = max(ret, ice);
            }
    return ret;
}

int sum_ice()
{
    int ret = 0;
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            ret += board[i][j];
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    SIZE = pow(2, n);
    board.resize(SIZE + 2, vector<int>(SIZE + 2, OUT_OF_BOUND));
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            cin >> board[i][j];
    while (k--)
    {
        int lv;
        cin >> lv;
        rotate_mat(lv);
        melt_ice();
    }
    cout << sum_ice() << '\n' << maxi_iceberg();
    return 0;
}