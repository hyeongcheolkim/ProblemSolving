#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edge;
int score[6][3];
bool flag = false;

void dfs(int level = 0)
{
    if (flag)
        return;
    if (level == edge.size())
    {
        bool tmp = true;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                tmp &= (score[i][j] == 0);
        flag |= tmp;
        return;
    }
    auto [a, b] = edge[level];

    --score[a][0];
    --score[b][2];
    dfs(level + 1);
    ++score[a][0];
    ++score[b][2];

    --score[b][0];
    --score[a][2];
    dfs(level + 1);
    ++score[b][0];
    ++score[a][2];

    --score[a][1];
    --score[b][1];
    dfs(level + 1);
    ++score[a][1];
    ++score[b][1];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 6; ++i)
        for (int j = i + 1; j < 6; ++j)
            edge.emplace_back(i, j);

    for (int t = 0; t < 4; ++t)
    {
        flag = false;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> score[i][j];
        dfs();
        cout << (flag ? 1 : 0) << ' ';
    }
    return 0;
}