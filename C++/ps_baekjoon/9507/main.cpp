#include <bits/stdc++.h>
using namespace std;

map<int, unsigned long long> cache;

unsigned long long koong(int n)
{
    auto& ret = cache[n];
    if (ret != 0)
        return ret;
    if (n < 2)
        return ret = 1;
    if (n == 2)
        return ret = 2;
    if (n == 3)
        return ret = 4;
    if (n > 3)
        return ret = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << koong(n) << '\n';
    }
    return 0;
}