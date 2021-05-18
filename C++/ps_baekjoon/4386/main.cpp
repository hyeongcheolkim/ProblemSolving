//baekjoon ps 4386

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
    int n;
    cin >> n;
    uf = new int[n];
    for (int i = 0; i < n; i++)
        uf[i] = i;
    vector<pair<double, double>> map(n);
    vector<tuple<double, char, char>> edge;
    edge.reserve(n * n + 1 / 2);
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        map[i] = {a, b};
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
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