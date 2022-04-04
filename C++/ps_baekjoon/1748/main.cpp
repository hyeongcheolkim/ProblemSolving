#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0;
    cin >> n;
    int len = log10(n + 1);
    int ea = pow(10, len) - 1;
    for (int i = 1; i <= len; ++i)
        res += i * 9 * static_cast<int>(pow(10, i - 1));
    res += (len + 1) * (n - ea);
    cout << res << '\n';
    return 0;
}