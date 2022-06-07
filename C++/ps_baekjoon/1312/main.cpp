#include <bits/stdc++.h>
using namespace std;

int a, b, n, res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> n;
    a %= b;
    while (n--)
    {
        a *= 10;
        if (a >= b)
        {
            res = a / b;
            a %= b;
        }
        else
            res = 0;
    }
    cout << res;
    return 0;
}