//baekjoon ps 2887

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

int *uf;

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
    int n;
    long long res = 0;
    cin >> n;
    uf = new int[n];
    for (int i = 0; i < n; i++)
        uf[i] = i;
    vector<pair<int, int>> X(n);
    vector<pair<int, int>> Y(n);
    vector<pair<int, int>> Z(n);
    vector<tuple<int, int, int>> edge;
    edge.reserve(3 * n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        X[i] = {x, i};
        Y[i] = {y, i};
        Z[i] = {z, i};
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    for (int i = 0; i < n - 1; i++)
    {
        edge.push_back({X[i + 1].first - X[i].first, X[i].second, X[i + 1].second});
        edge.push_back({Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second});
        edge.push_back({Z[i + 1].first - Z[i].first, Z[i].second, Z[i + 1].second});
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++)
        if (uni(get<1>(edge[i]), get<2>(edge[i])))
            res += get<0>(edge[i]);
    cout << res;
    delete[] uf;
    return 0;
}