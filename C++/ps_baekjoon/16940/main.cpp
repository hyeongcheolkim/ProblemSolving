#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
queue<int> q, order;
vector<bool> vst;

void print_zero_and_exit()
{
    cout << 0;
    exit(0);
}

int main()
{
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
    order.pop();
    vst[1] = true;
    q.push(1);
    while (!q.empty())
    {
        unordered_set<int> next_nodes;
        int now_node = q.front();
        q.pop();
        for (const auto& next_node : graph[now_node])
        {
            if (vst[next_node])
                continue;
            vst[next_node] = true;
            next_nodes.insert(next_node);
        }
        for (int i = 0; i < next_nodes.size(); ++i)
        {
            if (order.empty())
                print_zero_and_exit();
            int node = order.front();
            order.pop();
            if (next_nodes.contains(node))
                q.push(node);
            else
                print_zero_and_exit();
        }
    }
    cout << 1;
    return 0;
}