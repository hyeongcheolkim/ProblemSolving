//baekjoon ps 14567

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> degree(n + 1);
    vector<int> res(n + 1);
    queue<pair<int, int>> q;
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        ++degree[to];
    }
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
            q.emplace(i, 1);
    while (!q.empty())
    {
        auto [now_subject, now_semester] = q.front();
        res[now_subject] = now_semester;
        q.pop();
        for (int idx = 0; idx < graph[now_subject].size(); ++idx)
            if (int &next_subject = graph[now_subject][idx]; --degree[next_subject] == 0)
                q.emplace(next_subject, now_semester + 1);
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
    return 0;
}