#include <bits/stdc++.h>
using namespace std;

struct Area
{
    deque<int> trees;
    int fertilizer;
    Area(const int& fertilizer) { this->fertilizer = fertilizer; }
};

constexpr int OUT_OF_BOUND = -1;
constexpr int dr[]{-1, -1, -1, 0, 0, +1, +1, +1}, dc[]{-1, 0, +1, -1, +1, -1, 0, +1};
int n, m, k, cnt;
vector<vector<int>> gradient;
vector<vector<Area>> terrain;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    gradient.assign(n + 2, vector<int>(n + 2));
    terrain.assign(n + 2, vector<Area>(n + 2, Area(OUT_OF_BOUND)));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> gradient[i][j];
            terrain[i][j].fertilizer = 5;
        }
    while (m--)
    {
        int row, col, age;
        cin >> row >> col >> age;
        terrain[row][col].trees.emplace_back(age);
        sort(terrain[row][col].trees.begin(), terrain[row][col].trees.end());
    }
    while (k--)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                auto& cur = terrain[i][j];
                deque<int> temp;
                while (!cur.trees.empty() && cur.trees.front() <= cur.fertilizer)
                {
                    cur.fertilizer -= cur.trees.front();
                    temp.push_back(cur.trees.front() + 1);
                    cur.trees.pop_front();
                }
                while (!cur.trees.empty())
                {
                    cur.fertilizer += cur.trees.front() / 2;
                    cur.trees.pop_front();
                }
                cur.trees.swap(temp);
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                auto& cur = terrain[i][j];
                for (const auto& e : cur.trees)
                    if (e % 5 == 0)
                        for (int direction = 0; direction < 8; ++direction)
                        {
                            int nr = i + dr[direction];
                            int nc = j + dc[direction];
                            if (cur.fertilizer == OUT_OF_BOUND)
                                continue;
                            terrain[nr][nc].trees.push_front(1);
                        }
                cur.fertilizer += gradient[i][j];
            }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cnt += terrain[i][j].trees.size();
    cout << cnt;
    return 0;
}