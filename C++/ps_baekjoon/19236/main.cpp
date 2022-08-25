#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 4;
namespace BOARD { constexpr pair<int, int> OUT_OF_BOUND{-1, -1}, EMPTY{-2, -2}, SHARK{-3, -3}; }
namespace POS { constexpr pair<int, int> EATEN{-4, -4}; }
int maxi = 0;
map<int, pair<int, int>> diff{
    {1, {-1, 0}},
    {2, {-1, -1}},
    {3, {0, -1}},
    {4, {+1, -1}},
    {5, {+1, 0}},
    {6, {+1, +1}},
    {7, {0, +1}},
    {8, {-1, +1}},
};

int rotate_counter_clock(int direct)
{
    if (++direct > 8)
        direct = 1;
    return direct;
}

void fish_move(vector<vector<pair<int, int>>>& board, map<int, pair<int, int>>& pos)
{
    for (int i = 1; i <= 16; ++i)
    {
        auto p = pos[i];
        if (p == POS::EATEN)
            continue;
        auto [r, c] = p;
        int& direct = board[r][c].second;
        int cnt = 0, nr, nc;
        while (nr = r + diff[direct].first, nc = c + diff[direct].second, cnt < 8 && (board[nr][nc] == BOARD::SHARK || board[nr][nc] == BOARD::OUT_OF_BOUND))
        {
            direct = rotate_counter_clock(direct);
            ++cnt;
        }
        if (cnt == 8)
            continue;
        if (board[nr][nc] == BOARD::EMPTY)
            pos[board[r][c].first] = {nr, nc};
        else
            swap(pos[board[r][c].first], pos[board[nr][nc].first]);
        swap(board[r][c], board[nr][nc]);
    }
}

void dfs(vector<vector<pair<int, int>>> board, map<int, pair<int, int>> pos, pair<int, int> shark, int shark_direct, int acc)
{
    fish_move(board, pos);
    vector<pair<int, int>> target;
    auto [r, c] = shark;
    int nr = r, nc = c;
    while (nr += diff[shark_direct].first, nc += diff[shark_direct].second, board[nr][nc] != BOARD::OUT_OF_BOUND)
    {
        if (board[nr][nc] == BOARD::EMPTY)
            continue;
        target.emplace_back(nr, nc);
    }
    if (target.empty())
    {
        maxi = max(maxi, acc);
        return;
    }
    for (const auto& [tr, tc] : target)
    {
        auto tmp_board = board;
        auto tmp_pos = pos;
        auto [num, direct] = tmp_board[tr][tc];
        tmp_pos[num] = POS::EATEN;
        tmp_board[r][c] = BOARD::EMPTY;
        tmp_board[tr][tc] = BOARD::SHARK;
        dfs(tmp_board, tmp_pos, {tr, tc}, direct, acc + num);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vector<vector<pair<int, int>>> board;
    map<int, pair<int, int>> pos;
    board.resize(SIZE + 2, vector<pair<int, int>>(SIZE + 2, BOARD::OUT_OF_BOUND));
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
        {
            int a, b;
            cin >> a >> b;
            pos[a] = {i, j};
            board[i][j] = {a, b};
        }
    int tmp_sum = board[1][1].first;
    pair<int, int> shark = {1, 1};
    int shark_direct = board[1][1].second;
    pos[board[1][1].first] = POS::EATEN;
    board[1][1] = BOARD::SHARK;
    dfs(board, pos, shark, shark_direct, tmp_sum);
    cout << maxi;
    return 0;
}