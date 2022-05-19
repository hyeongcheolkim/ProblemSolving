#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    while (cin >> n >> k, !(n == 0 && k == 0))
    {
        k = min(k, n - k);
        long long ret = 1;
        for (int i = 1; i <= k; ++i, --n)
            ret = ret * n / i;
        cout << ret << '\n';
    }
    return 0;
}