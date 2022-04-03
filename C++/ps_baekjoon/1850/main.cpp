#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long a, b;
    cin >> a >> b;
    long long len = gcd(a, b);
    while (len--)
        cout.put('1');
    return 0;
}