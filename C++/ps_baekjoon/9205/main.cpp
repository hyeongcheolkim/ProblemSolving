#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

int distance(const pos& a, const pos& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pos> node;
        vector<vector<bool>> graph;
        node.reserve(n + 2);
        graph.resize(n + 2, vector<bool>(n + 2));
        for (int i = 0; i < n + 2; ++i)
        {
            int x, y;
            cin >> x >> y;
            node.emplace_back(x, y);
        }
        for (int i = 0; i < n + 2; ++i)
            for (int j = 0; j < n + 2; ++j)
                if (distance(node[i], node[j]) <= 1000)
                    graph[i][j] = true;
        for (int k = 0; k < n + 2; ++k)
            for (int i = 0; i < n + 2; ++i)
                for (int j = 0; j < n + 2; ++j)
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
        if (graph.front().back())
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    return 0;
}