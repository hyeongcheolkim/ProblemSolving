#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
queue<int> order;
vector<bool> vst;

void print_zero_and_exit()
{
    cout << 0;
    exit(0);
}

void trace(int now_node)
{
    set<int> next_nodes;
    for (const auto& next_node : graph[now_node])
    {
        if (vst[next_node])
            continue;
        vst[next_node] = true;
        next_nodes.insert(next_node);
    }
    while (!next_nodes.empty())
        if (int next_node = order.front(); next_nodes.contains(next_node))
        {
            order.pop();
            next_nodes.erase(next_node);
            trace(next_node);
        }
        else
            print_zero_and_exit();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    graph.resize(n + 1);
    vst.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 0; i < n; ++i)
    {
        int node;
        cin >> node;
        order.push(node);
    }
    if (order.front() != 1)
        print_zero_and_exit();
    vst[1] = true;
    order.pop();
    trace(1);
    cout << 1;
    return 0;
}