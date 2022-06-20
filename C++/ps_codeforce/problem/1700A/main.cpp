#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long res = 0;
        res += (m) * (m - 1) / 2;
        res += (n) * (n + 1) / 2 * m;
        cout << res << '\n';
    }
    return 0;
}