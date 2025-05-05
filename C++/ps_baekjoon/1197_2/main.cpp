#include <bits/stdc++.h>
using namespace std;

int v, e;

bool cmp(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(&cmp)> pq(cmp);

vector<int> root;

int find(int x)
{
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool is_uni(int a, int b)
{
    a = find(a);
    b = find(b);
    return a == b;
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    root[a] = b;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> v >> e;
    root.resize(v + 1);
    for (int i = 0; i <= v; ++i)
        root[i] = i;

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.emplace(a, b, c);
    }
    int cnt = 0;
    int w = 0;
    while (!pq.empty() && cnt != v - 1)
    {
        auto [a, b, c] = pq.top();
        pq.pop();
        if (!is_uni(a, b))
        {
            uni(a, b);
            w += c;
            ++cnt;
        }
    }
    cout << w;
    return 0;
}