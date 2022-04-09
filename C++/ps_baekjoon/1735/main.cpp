#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n1, dn1, n2, dn2;
    cin >> n1 >> dn1 >> n2 >> dn2;
    int n = n1 * dn2 + n2 * dn1;
    int dn = dn1 * dn2;
    int _gcd = gcd(n, dn);
    cout << n / _gcd << ' ' << dn / _gcd;
    return 0;
}