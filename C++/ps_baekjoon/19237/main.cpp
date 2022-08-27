#include <bits/stdc++.h>
using namespace std;

struct Shark
{
    int row, col, direct;
    const bool operator == (const Shark& that) const
    {
        return this->row == that.row && this->col == that.col;
    }
};
constexpr pair<int, int> OUT_OF_BOUND{-1, -1};
constexpr Shark DEAD{-2, -2, -2};
int n, m, k, cnt, tick;
vector<vector<pair<int, int>>> board;
map<int, map<int, vector<int>>> prior;
map<int, Shark> sharks;
map<int, pair<int, int>> diff{
    {1, {-1, 0}},
    {2, {+1, 0}},
    {3, {0, -1}},
    {4, {0, +1}},
};

void emit_smell()
{
    for (int lv = 1; lv <= m; ++lv)
        if (sharks[lv] != DEAD)
            board[sharks[lv].row][sharks[lv].col] = {lv, k};
}

void reduce_smell()
{
    for (int lv = 1; lv <= m; ++lv)
        if (sharks[lv] != DEAD)
            ++board[sharks[lv].row][sharks[lv].col].second;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (board[i][j].second > 0)
                --board[i][j].second;
}

void move_shark()
{
    for (int lv = 1; lv <= m; ++lv)
        if (sharks[lv] != DEAD)[&]
        {
            auto [r, c, d] = sharks[lv];
            for (const auto& direct : prior[lv][d])
            {
                const auto& [dr, dc] = diff[direct];
                int nr = r + dr;
                int nc = c + dc;
                if (board[nr][nc] == OUT_OF_BOUND || board[nr][nc].second != 0)
                    continue;
                sharks[lv].row = nr;
                sharks[lv].col = nc;
                sharks[lv].direct = direct;
                return;
            }
            for (const auto& direct : prior[lv][d])
            {
                const auto& [dr, dc] = diff[direct];
                int nr = r + dr;
                int nc = c + dc;
                if (board[nr][nc] == OUT_OF_BOUND || board[nr][nc].first != lv)
                    continue;
                sharks[lv].row = nr;
                sharks[lv].col = nc;
                sharks[lv].direct = direct;
                return;
            }
        }();
}

void kill_shark()
{
    for (int i = 1; i <= m; ++i)
        if (sharks[i] != DEAD)
            for (int j = i + 1; j <= m; ++j)
                if (sharks[i] == sharks[j])
                {
                    sharks[j] = DEAD;
                    --cnt;
                }
}

void init()
{
    cin >> n >> m >> k;
    board.resize(n + 2, vector<pair<int, int>>(n + 2, OUT_OF_BOUND));
    cnt = m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int lv;
            cin >> lv;
            board[i][j] = {0, 0};
            if (lv == 0)
                continue;
            sharks[lv].row = i;
            sharks[lv].col = j;
        }
    for (int lv = 1; lv <= m; ++lv)
        cin >> sharks[lv].direct;
    for (int lv = 1; lv <= m; ++lv)
        for (int direct = 1; direct <= 4; ++direct)
        {
            prior[lv][direct].resize(4);
            for (int ea = 0; ea < 4; ++ea)
                cin >> prior[lv][direct][ea];
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    init();
    emit_smell();
    while (tick <= 1000 && cnt != 1)
    {
        move_shark();
        kill_shark();
        emit_smell();
        reduce_smell();
        ++tick;
    }
    if (tick > 1000)
        cout << -1;
    else
        cout << tick;
    return 0;
}