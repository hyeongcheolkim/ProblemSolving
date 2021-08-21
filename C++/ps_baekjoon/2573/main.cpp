//baekjoon ps 2573

#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;
constexpr int OUT_OF_BOUND = -1;
constexpr int dr[] = {0, 0, +1, -1};
constexpr int dc[] = {+1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sea(n + 2, vector<int>(m + 2, OUT_OF_BOUND));
    map<pos, int> iceberg;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> sea[i][j];
            if (sea[i][j])
                iceberg[pos{i, j}] = sea[i][j];
        }
    for (int year = 0; !iceberg.empty(); ++year)
    {
        vector<vector<bool>> visit(n + 2, vector<bool>(m + 2));
        int island = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (sea[i][j] && !visit[i][j])
                {
                    queue<pos> q;
                    ++island;
                    visit[i][j] = true;
                    q.emplace(i, j);
                    while (!q.empty())
                    {
                        auto [now_row, now_col] = q.front();
                        q.pop();
                        int diff = 0;
                        for (int direction = 0; direction < sizeof(dr) / sizeof(int); ++direction)
                        {
                            int next_row = now_row + dr[direction];
                            int next_col = now_col + dc[direction];
                            if (sea[next_row][next_col] == 0)
                            {
                                ++diff;
                                continue;
                            }
                            if (sea[next_row][next_col] == OUT_OF_BOUND || visit[next_row][next_col])
                                continue;
                            visit[next_row][next_col] = true;
                            q.emplace(next_row, next_col);
                        }
                        iceberg[pos{now_row, now_col}] -= diff;
                    }
                }
        if (island >= 2)
        {
            cout << year;
            exit(0);
        }
        for (auto iter = iceberg.begin(); iter != iceberg.end();)
        {
            auto [position, height] = *iter;
            auto [row, col] = position;
            if (height <= 0)
            {
                height = 0;
                iceberg.erase(iter++);
            }
            else
                ++iter;
            sea[row][col] = height;
        }
    }
    cout << 0;
    return 0;
}