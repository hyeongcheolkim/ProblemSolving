#include <bits/stdc++.h>
using namespace std;

int n, k, turn = 1;
vector<vector<int>> terrain;
vector<vector<vector<pair<int, int>>>> board;
vector<pair<int, int>> pos;
map<int, pair<int, int>> Direct{
    {1, {0, +1}},
    {2, {0, -1}},
    {3, {-1, 0}},
    {4, {+1, 0}},
};
enum { WHITE, RED, BLUE };

void rotate_counter(int& direct)
{
    if (direct == 1)
        direct = 2;
    else if (direct == 2)
        direct = 1;
    else if (direct == 3)
        direct = 4;
    else if (direct == 4)
        direct = 3;
}

bool move_piece(int idx, bool flag = false)
{
    const auto& [row, col] = pos[idx];
    if (board[row][col].front().first != idx)
        return false;
    auto tmp_vec = move(board[row][col]);
    const auto& [dr, dc] = Direct[tmp_vec.front().second];
    int nr = row + dr;
    int nc = col + dc;
    switch (terrain[nr][nc])
    {
        case RED:
            reverse(tmp_vec.begin(), tmp_vec.end());
        case WHITE:
            board[nr][nc].insert(board[nr][nc].end(), tmp_vec.begin(), tmp_vec.end());
            for (const auto& [idx, ignore] : tmp_vec)
                pos[idx] = {nr, nc};
            if (board[nr][nc].size() >= 4)
                return true;
            break;
        case BLUE:
            if (flag)
            {
                board[row][col].insert(board[row][col].end(), tmp_vec.begin(), tmp_vec.end());
                if (board[row][col].size() >= 4)
                    return true;
            }
            else
            {
                rotate_counter(tmp_vec.front().second);
                board[row][col].insert(board[row][col].end(), tmp_vec.begin(), tmp_vec.end());
                return move_piece(idx, true);
            }
            break;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    terrain.resize(n + 2, vector<int>(n + 2, BLUE));
    board.resize(n + 2, vector<vector<pair<int, int>>>(n + 2));
    pos.resize(k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> terrain[i][j];
    for (int idx = 0; idx < k; ++idx)
    {
        int row, col, direct;
        cin >> row >> col >> direct;
        pos[idx].first = row;
        pos[idx].second = col;
        board[row][col].emplace_back(idx, direct);
    }
    while (turn <= 1000)
    {
        for (int idx = 0; idx < k; ++idx)
            if (move_piece(idx))
            {
                cout << turn;
                exit(0);
            }
        ++turn;
    }
    cout << -1;
    return 0;
}