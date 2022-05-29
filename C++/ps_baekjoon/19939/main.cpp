#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    n -= k * (k + 1) / 2;
    if (n < 0)
        cout << -1;
    else if (n % k == 0)
        cout << k - 1;
    else
        cout << k;
    return 0;
}