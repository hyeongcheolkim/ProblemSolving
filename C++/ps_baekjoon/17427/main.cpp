#include <bits/stdc++.h>
using namespace std;

int n;
long long res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        res += (n / i) * i;
    cout << res;
    return 0;
}