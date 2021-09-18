#include <bits/stdc++.h>
using namespace std;
using edge = tuple<int, int, int>;

constexpr int mxN = 1e3;
int n, cnt, uf[mxN + 1];
unsigned long long total_cost;
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
        uf[a] = b;
        return true;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        uf[i] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int input;
            cin >> input;
            if (i >= j)
                continue;
            pq.emplace(input, i, j);
        }
    while (cnt != n - 1)
    {
        auto [cost, vertex1, vertex2] = pq.top();
        pq.pop();
        if (uni(vertex1, vertex2))
        {
            ++cnt;
            total_cost += cost;
        }
    }
    cout << total_cost;
    return 0;
}