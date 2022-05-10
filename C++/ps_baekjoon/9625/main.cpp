#include <bits/stdc++.h>
using namespace std;

int k, a = 1, b = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;
    while (k--)
    {
        int new_a = b;
        b += a;
        a = new_a;
    }
    cout << a << ' ' << b;
    return 0;
}