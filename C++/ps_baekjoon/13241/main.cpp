#include <bits/stdc++.h>
using namespace std;

long long _gcd(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    while (b != 0)
    {
        long long q = a / b;
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long a, b;
    cin >> a >> b;
    int gcd_val = _gcd(a, b);
    cout << a * b / gcd_val;
    return 0;
}