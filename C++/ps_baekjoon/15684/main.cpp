#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m, h, mini = INF;
vector<int> line;
vector<vector<bool>> vst;
vector<pair<int, int>> bridge;

bool game()
{
    auto cmp = line;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j < n; ++j)
            if (vst[i][j])
                swap(cmp[j], cmp[j + 1]);
    return cmp == line;
}

void dfs(int level = 0, int idx = 0)
{
    if (game())
    {
        mini = min(mini, level);
        return;
    }
    if (level >= 3)
        return;
    for (int i = idx; i < bridge.size(); ++i)
    {
        auto [r, c] = bridge[i];
        if (vst[r][c - 1])
            continue;
        vst[r][c] = true;
        dfs(level + 1, i + 1);
        vst[r][c] = false;
    }
}

int main()
{
    cin >> n >> m >> h;
    line.resize(n + 1);
    vst.resize(h + 1, vector<bool>(n + 1));
    iota(line.begin(), line.end(), 0);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        vst[a][b] = true;
    }
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j < n; ++j)
            if (!vst[i][j] && !vst[i][j + 1])
                bridge.emplace_back(i, j);
    dfs();
    cout << (mini == INF ? -1 : mini);
    return 0;
}