//baekjoon ps 2606

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int vertex, edge, cnt = 0;
    cin >> vertex >> edge;
    vector<vector<int>> map(vertex + 1);
    queue<int> q;
    vector<bool> check(vertex + 1, false);
    for (int i = 0; i < edge; i++)
    {
        static int to, go;
        cin >> to >> go;
        map[to].push_back(go);
        map[go].push_back(to);
    }
    q.push(1);
    check[1] = true;
    while (!q.empty())
    {
        for (const auto &e : map[q.front()])
            if (!check[e])
            {
                q.push(e);
                check[e] = true;
            }
        q.pop();
        cnt++;
    }
    cout << cnt-1;
    return 0;
}