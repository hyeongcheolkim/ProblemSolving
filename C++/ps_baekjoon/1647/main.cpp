//baekjoon ps 1647

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int *uf;

int find(const int &num)
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
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, cnt = 0;
    int res = 0, maxi = -1;
    cin >> n >> m;
    uf = new int[n + 1];
    for (int i = 0; i <= n; i++)
        uf[i] = i;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    while (m--)
    {
        int to, go, cost;
        cin >> to >> go >> cost;
        pq.push({cost, to, go});
    }
    while (!pq.empty())
    {
        if (cnt == n - 1)
            break;
        int cost = get<0>(pq.top());
        int to = get<1>(pq.top());
        int go = get<2>(pq.top());
        pq.pop();
        if(uni(to,go))
        {
            res += cost;
            maxi = max(maxi, cost);
        }
    }
    cout << res - maxi;
    delete[] uf;
    return 0;
}