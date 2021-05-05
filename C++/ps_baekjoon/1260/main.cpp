//baekjoon ps 1260

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check_dfs[1001];
bool check_bfs[1001];
void dfs(int num, const vector<vector<int>> &map)
{
    if (!check_dfs[num])
    {
        cout << num << " ";
        check_dfs[num] = true;
        for (const auto &e : map[num])
            dfs(e, map);
    }
}

void bfs(int num, const vector<vector<int>> &map)
{
    queue<int> q;
    q.push(num);
    while (!q.empty())
    {
        for (const auto &e : map[q.front()])
            if (!check_bfs[e])
                q.push(e);
        if (!check_bfs[q.front()])
        {
            cout << q.front() << " ";
            check_bfs[q.front()] = true;
        }
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> map(n + 1);
    for (int i = 1; i <= m; i++)
    {
        static int to, go;
        cin >> to >> go;
        map[to].push_back(go);
        map[go].push_back(to);
    }
    for (int i = 1; i <= n; i++)
        sort(map[i].begin(), map[i].end());
    dfs(v, map);
    cout << '\n';
    bfs(v, map);
    return 0;
}