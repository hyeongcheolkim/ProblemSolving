#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> depth, parent;
vector<bool> vst;
vector<vector<int>> graph;

void calculate_depth(int node = 1, int dep = 0)
{
    depth[node] = dep;
    vst[node] = true;
    for (const auto& next : graph[node])
        if (!vst[next])
        {
            parent[next] = node;
            calculate_depth(next, dep + 1);
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    depth.resize(n + 1);
    parent.resize(n + 1);
    vst.resize(n + 1);
    graph.resize(n + 1);
    while (--n)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    calculate_depth();
    cin >> m;
    while (m--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        while (depth[n1] != depth[n2])
        {
            if (depth[n1] > depth[n2])
                n1 = parent[n1];
            else
                n2 = parent[n2];
        }
        while (n1 != n2)
        {
            n1 = parent[n1];
            n2 = parent[n2];
        }
        cout << n1 << '\n';
    }
    return 0;
}