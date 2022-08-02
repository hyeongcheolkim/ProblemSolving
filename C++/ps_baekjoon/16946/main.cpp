#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m;
vector<vector<int>> board, cost;
vector<vector<pair<int, int>>> uf;

pair<int, int> find(pair<int, int> pos)
{
    if (pos == uf[pos.first][pos.second])
        return pos;
    return uf[pos.first][pos.second] = find(uf[pos.first][pos.second]);
}

void uni(pair<int, int> a, pair<int, int> b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        uf[b.first][b.second] = a;
}

bool is_uni(pair<int, int> a, pair<int, int> b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        return false;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(m + 2, -1));
    cost.resize(n + 2, vector<int>(m + 2));
    uf.resize(n + 2, vector<pair<int, int>>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char buff;
            cin >> buff;
            board[i][j] = buff - '0';
            uf[i][j] = {i, j};
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (board[i][j] == 0 && cost[i][j] == 0)
            {
                queue<pair<int, int>> q;
                vector<pair<int, int>> tmp;
                q.emplace(i, j);
                tmp.emplace_back(i, j);
                cost[i][j] = true;
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (board[nr][nc] == -1 || board[nr][nc] == 1)
                            continue;
                        if (cost[nr][nc])
                            continue;
                        uni(pair<int, int>{i, j}, pair<int, int>{nr, nc});
                        cost[nr][nc] = true;
                        q.emplace(nr, nc);
                        tmp.emplace_back(nr, nc);
                    }
                }
                for (const auto& [r, c] : tmp)
                    cost[r][c] = tmp.size();
            }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            if (board[i][j] == 1)
            {
                int total_cost = 1;
                vector<pair<int, int>> target;
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = i + dr[direction];
                    int nc = j + dc[direction];
                    if (board[nr][nc] == -1 || board[nr][nc] == 1)
                        continue;
                    target.emplace_back(nr, nc);
                }
                while (!target.empty())[&]()->void
                {
                    auto t = target.back();
                    target.pop_back();
                    for (const auto& e : target)
                        if (is_uni(t, e))
                            return;
                    total_cost += cost[t.first][t.second] % 10;
                    total_cost %= 10;
                }();
                cout << total_cost;
            }
            else
                cout << 0;
        cout << '\n';
    }
    return 0;
}