#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull n;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    ull sq = sqrt(n);
    while (sq * sq > n)
        --sq;
    if (sq * sq == n)
        cout << sq;
    else
        cout << sq + 1;
    return 0;
}