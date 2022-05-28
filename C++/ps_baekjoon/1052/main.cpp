#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e7;
int n, k;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (unsigned long long i = n; i <= numeric_limits<unsigned long long>::max(); ++i)
        if (__popcount(i) <= k)
        {
            cout << i - n;
            exit(0);
        }
    cout << -1;
    return 0;
}