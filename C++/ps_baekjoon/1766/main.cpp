//baekjoon ps 1766

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
    vector<vector<int>> map(n + 1);
    vector<int> degree(n + 1);
    priority_queue<int, vector<int>, greater<int>> pq;
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        map[from].push_back(to);
        degree[to]++;
    }
    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        int now = pq.top();
        cout << now << ' ';
        pq.pop();
        for (int i = 0; i < map[now].size(); i++)
        {
            int next = map[now][i];
            if (--degree[next] == 0)
                pq.push(next);
        }
    }
    return 0;
}