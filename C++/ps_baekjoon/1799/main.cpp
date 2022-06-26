#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1;
int n, maxi_white, maxi_black;
vector<vector<int>> board;
vector<vector<bool>> vst;
vector<pair<int, int>> white_pos, black_pos;

bool putable(int row, int col)
{
    static const vector<pair<int, int>> diff{
        {+1, +1},
        {-1, -1},
        {+1, -1},
        {-1, +1},
    };
    for (const auto& [dr, dc] : diff)
    {
        int r = row, c = col;
        while (board[r][c] != OUT_OF_BOUND)
        {
            if (vst[r][c])
                return false;
            r += dr;
            c += dc;
        }
    }
    return true;
}

void dfs(const vector<pair<int, int>>& arr, int idx = 0, int cnt = 0)
{
    if (idx == arr.size())
    {
        if (&arr == &white_pos)
            maxi_white = max(maxi_white, cnt);
        if (&arr == &black_pos)
            maxi_black = max(maxi_black, cnt);
        return;
    }
    auto [r, c] = arr[idx];
    dfs(arr, idx + 1, cnt);
    if (putable(r, c))
    {
        vst[r][c] = true;
        dfs(arr, idx + 1, cnt + 1);
        vst[r][c] = false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    vst.resize(n + 2, vector<bool>(n + 2));
    bool tick = false;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j])
            {
                if (tick)
                    white_pos.emplace_back(i, j);
                else
                    black_pos.emplace_back(i, j);
            }
            tick = !tick;
        }
        if (n % 2 == 0)
            tick = !tick;
    }
    dfs(white_pos);
    dfs(black_pos);
    cout << maxi_white + maxi_black;
    return 0;
}