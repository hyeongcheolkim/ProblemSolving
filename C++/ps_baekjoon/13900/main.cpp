#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int n;
vector<ull> acc;
ull res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    acc.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> acc[i];
        acc[i] += acc[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        res += (acc[i] - acc[i - 1]) * (acc[n] - acc[i]);
    cout << res;
    return 0;
}