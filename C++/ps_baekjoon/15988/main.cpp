#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'009;
constexpr int mxN = 1e6;
int cache[mxN + 1];

int solve(int num)
{
    int& ret = cache[num];
    if (ret != 0)
        return ret;
    if (num == 1)
        return ret = 1;
    if (num == 2)
        return ret = 2;
    if (num == 3)
        return ret = 4;
    return ret = ((solve(num - 1) + solve(num - 2)) % MOD + solve(num - 3)) % MOD;
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
        cout << solve(n) << '\n';
    }
    return 0;
}