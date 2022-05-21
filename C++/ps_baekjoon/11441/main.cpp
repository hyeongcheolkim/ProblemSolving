#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> acc;

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
    cin >> m;
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << acc[j] - acc[i - 1] << '\n';
    }
    return 0;
}