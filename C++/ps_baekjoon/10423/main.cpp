#include <bits/stdc++.h>
using namespace std;
using vertex = tuple<int, int, int>;

constexpr int mxN = 1e3;
int n, m, k, res, uf[mxN + 1];
priority_queue<vertex, vector<vertex>, greater<vertex>> pq;

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
        uf[b] = a;
        return true;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        uf[i] = i;
    for (int i = 0; i < k; ++i)
    {
        int plant_now = 0, plant_pre = 0;
        cin >> plant_now;
        uni(plant_now, plant_pre);
        plant_pre = plant_now;
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.emplace(w, u, v);
    }
    while (!pq.empty())
    {
        auto [cost, vertex1, vertex2] = pq.top();
        pq.pop();
        if (uni(vertex1, vertex2))
            res += cost;
    }
    cout << res;
    return 0;
}