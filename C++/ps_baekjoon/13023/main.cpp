//baekjoon ps 13023

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, res = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    function<void(int, int)> dfs = [&](int now_vertex, int level)
    {
        static vector<bool> visit(n);
        if (res == 1)
            return;
        if (level == 4)
        {
            res = 1;
            return;
        }
        visit[now_vertex] = true;
        for (int i = 0; i < graph[now_vertex].size(); ++i)
        {
            int next_vertex = graph[now_vertex][i];
            if (visit[next_vertex])
                continue;
            dfs(next_vertex, level + 1);
        }
        visit[now_vertex] = false;
    };
    for (int i = 0; i < n; ++i)
    {
        dfs(i, 0);
        if (res == 1)
            break;
    }
    cout << res;
    return 0;
}