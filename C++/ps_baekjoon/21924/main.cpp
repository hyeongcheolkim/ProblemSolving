#include <bits/stdc++.h>
using namespace std;
using edge = tuple<int, int, int>;

int n, m, cnt = 1;
long long mini, total_cost;
vector<int> uf;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int find(int num)
{
    if (uf[num] == num)
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
    cin >> n >> m;
    uf.resize(n + 1);
    iota(uf.begin(), uf.end(), 0);
    while (m--)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        total_cost += cost;
        pq.emplace(cost, a, b);
    }
    while (!pq.empty() && cnt != n)
    {
        auto [cost, a, b] = pq.top();
        pq.pop();
        if (uni(a, b))
        {
            mini += cost;
            ++cnt;
        }
    }
    if (cnt == n)
        cout << total_cost - mini;
    else
        cout << -1;
    return 0;
}