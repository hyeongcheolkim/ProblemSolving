#include <bits/stdc++.h>
using namespace std;

long long m, a, b;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> a >> b;
    int q = m / (a + b);
    cout << q * a + min(a, (m - q * (a + b)));
    return 0;
}