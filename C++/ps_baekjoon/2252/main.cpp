//baekjoon ps 2252

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> degree(n + 1);
    vector<vector<int>> graph(n + 1);
    queue<int> q;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }
    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        cout << num << ' ';
        for (int i = 0; i < graph[num].size(); i++)
            if (--degree[graph[num][i]] == 0)
                q.push(graph[num][i]);
    }
    return 0;
}