//baekjoon ps 6497

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using edge = tuple<int, int, int>;

vector<int> uf;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n;
    while (cin >> m >> n, !(m == 0 && n == 0))
    {
        int saving = 0, total = 0, cnt = 0;
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        uf = vector<int>(m);
        for (int i = 0; i < m; ++i)
            uf[i] = i;
        while (n--)
        {
            int from, to, cost;
            cin >> from >> to >> cost;
            pq.emplace(cost, from, to);
            total += cost;
        }
        while (!pq.empty())
        {
            auto [cost, from, to] = pq.top();
            pq.pop();
            if (uni(from, to))
            {
                saving += cost;
                ++cnt;
            }
            if (cnt == m - 1)
                break;
        }
        cout << total - saving << '\n';
    }
    return 0;
}