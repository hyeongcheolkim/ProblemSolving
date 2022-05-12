#include <bits/stdc++.h>
using namespace std;

int n, maxi;
vector<vector<bool>> graph;
vector<vector<bool>> friends;

void dfs(int start, int now, int level = 0)
{
    if (level == 2)
        return;
    for (int i = 0; i < n; ++i)
        if (graph[now][i] && start != i)
        {
            friends[start][i] = true;
            dfs(start, i, level + 1);
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    graph.resize(n, vector<bool>(n));
    friends.resize(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            char tmp;
            cin >> tmp;
            graph[i][j] = (tmp == 'Y');
        }
    for (int i = 0; i < n; ++i)
    {
        dfs(i, i);
        maxi = max(maxi, (int)count(friends[i].begin(), friends[i].end(), true));
    }
    cout << maxi;
    return 0;
}