#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int l, p, v, idx = 0;
    while (++idx, cin >> l >> p >> v, !(l == 0 && p == 0 && v == 0))
        cout << "Case " << idx << ": " << l * (v / p) + min(v % p, l) << '\n';
    return 0;
}