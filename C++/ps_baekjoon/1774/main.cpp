//baekjoon ps 1774

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>
#include <vector>
#include <utility>

using namespace std;

int *uf;
double dis(const pair<double, double> &a, const pair<double, double> &b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int find(int num)
{
    if (num == uf[num])
        return num;
    else
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
    double res = 0;
    int n, m;
    cin >> n >> m;
    uf = new int[n + 1];
    for (int i = 1; i <= n; i++)
        uf[i] = i;
    vector<pair<double, double>> map(n + 1);
    vector<tuple<double, int, int>> edge;
    edge.reserve((n + 1) * (n + 2) / 2);
    for (int i = 1; i <= n; i++)
    {
        double a, b;
        cin >> a >> b;
        map[i] = {a, b};
    }
    for (int i = 0; i < m; i++)
    {
        double a, b;
        cin >> a >> b;
        uni(a, b);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            edge.push_back({dis(map[i], map[j]), i, j});
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++)
        if (uni(get<1>(edge[i]), get<2>(edge[i])))
            res += get<0>(edge[i]);
    cout.precision(2);
    cout << fixed << res;
    delete[] uf;
    return 0;
}