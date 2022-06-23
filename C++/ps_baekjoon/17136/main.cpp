#include <bits/stdc++.h>
using namespace std;

constexpr int BOARD_SIZE = 10, INF = numeric_limits<int>::max() / 2;
vector<vector<char>> board;
vector<pair<int, int>> pos;
vector<int> paper_ea;
int res = INF;

bool can_put_paper(int row, int col, int paper_size)
{
    if (!((row + paper_size) <= BOARD_SIZE && (col + paper_size) <= BOARD_SIZE))
        return false;
    bool all_one = true;
    for (int r = row; r < row + paper_size; ++r)
        for (int c = col; c < col + paper_size; ++c)
            all_one &= (board[r][c] == '1');
    return all_one;
}

void put_paper(int row, int col, int paper_size)
{
    for (int r = row; r < row + paper_size; ++r)
        for (int c = col; c < col + paper_size; ++c)
            board[r][c] = '0';
    ++paper_ea[paper_size];
}

void remove_paper(int row, int col, int paper_size)
{
    for (int r = row; r < row + paper_size; ++r)
        for (int c = col; c < col + paper_size; ++c)
            board[r][c] = '1';
    --paper_ea[paper_size];
}


void dfs(int idx = 0, int cnt = 0)
{
    int cur = idx;
    while (board[pos[cur].first][pos[cur].second] == '0')
        if (++cur >= BOARD_SIZE * BOARD_SIZE)
        {
            res = min(res, cnt);
            return;
        }
    if (cnt >= res)
        return;
    auto [r, c] = pos[cur];
    for (int paper_size = 5; paper_size >= 1; --paper_size)
    {
        if (paper_ea[paper_size] >= 5 || !can_put_paper(r, c, paper_size))
            continue;
        put_paper(r, c, paper_size);
        dfs(cur + 1, cnt + 1);
        remove_paper(r, c, paper_size);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    board.resize(BOARD_SIZE, vector<char>(BOARD_SIZE));
    paper_ea.resize(5 + 1);
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            cin >> board[i][j];
            pos.emplace_back(i, j);
        }
    dfs();
    cout << (res == INF ? -1 : res);
    return 0;
}