#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    long long ea = 9;
    long long weight = 1;
    long long ret = 0;
    while (k > weight * ea)
    {
        k -= weight * ea;
        ret += ea;
        ea *= 10;
        ++weight;
    }
    ret = (ret + 1) + (k - 1) / weight;
    if (ret > n)
        cout << -1;
    else
        cout << to_string(ret)[(k - 1) % weight];
    return 0;
}