//baekjoon ps 16234

#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;

int main()
{
    constexpr int OUT_OF_BOUND = -1;
    constexpr int dr[] = {0, 0, +1, -1};
    constexpr int dc[] = {+1, -1, 0, 0};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l, r, cnt = 0;
    cin >> n >> l >> r;
    vector<vector<int>> map(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> map[i][j];
    queue<pos> q;
    while (true)
    {
        bool flag = false;
        vector<vector<bool>> visit(n + 2, vector<bool>(n + 2, false));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (!visit[i][j])
                {
                    vector<pos> country;
                    visit[i][j] = true;
                    q.emplace(i, j);
                    int sum = map[i][j];
                    while (!q.empty())
                    {
                        auto [now_row, now_col] = q.front();
                        country.push_back(q.front());
                        q.pop();
                        for (int direction = 0; direction < sizeof(dr) / sizeof(int); ++direction)
                        {
                            int next_row = now_row + dr[direction];
                            int next_col = now_col + dc[direction];
                            int difference = abs(map[now_row][now_col] - map[next_row][next_col]);
                            if (map[next_row][next_col] == OUT_OF_BOUND || visit[next_row][next_col])
                                continue;
                            if (l <= difference && difference <= r)
                            {
                                visit[next_row][next_col] = true;
                                q.emplace(next_row, next_col);
                                sum += map[next_row][next_col];
                            }
                        }
                    }
                    if (country.size() >= 2)
                    {
                        flag = true;
                        int population = sum / country.size();
                        for (const auto &position : country)
                        {
                            auto [row, col] = position;
                            map[row][col] = population;
                        }
                    }
                }
        if (flag)
            ++cnt;
        else
            break;
    }
    cout << cnt;
    return 0;
}