#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dist;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dist.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> dist[i];
    sort(dist.begin(), dist.end());
    cout << dist[(n - 1) / 2];
    return 0;
}