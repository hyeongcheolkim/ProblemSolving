#include <bits/stdc++.h>
using namespace std;
using edge = tuple<int, int, int>;

constexpr int mxN = 1e3;
int n, m, sum, cnt, uf[mxN + 1];
char gender[mxN + 1];
vector<edge> graph;

int find(int num)
{
    if (num == uf[num])
        return num;
    return uf[num] = find(uf[num]);
}

bool uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        uf[a] = b;
        return true;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.reserve(m);
    for (int i = 1; i <= n; ++i)
    {
        cin >> gender[i];
        uf[i] = i;
    }
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (gender[from] == gender[to])
            continue;
        graph.emplace_back(cost, from, to);
    }
    sort(graph.begin(), graph.end());
    for (const auto &e : graph)
    {
        auto [now_cost, vertex_a, vertex_b] = e;
        if (uni(vertex_a, vertex_b))
        {
            sum += now_cost;
            ++cnt;
        }
        if (cnt == n - 1)
            break;
    }
    cout << (cnt == n - 1 ? sum : -1);
    return 0;
}