#include <bits/stdc++.h>
using namespace std;

constexpr int mxNM = 100, NOT_VST = -1;
int n, m, k, dp[mxNM + 1][mxNM + 1];

int fnc(int a = n, int z = m)
{
    auto& ret = dp[a][z];
    if (dp[a][z] != NOT_VST)
        return ret;
    if (a == 0 || z == 0)
        return ret = 1;
    ret = fnc(a - 1, z) + fnc(a, z - 1);
    if (ret > 1'000'000'000)
        ret = 1'000'000'000 + 1;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, NOT_VST, sizeof(dp));
    cin >> n >> m >> k;
    fnc();
    if (dp[n][m] < k)
    {
        cout << -1;
        return 0;
    }
    while (true)
    {
        if (n == 0 || m == 0)
        {
            while (n--)
                cout << 'a';
            while (m--)
                cout << 'z';
            break;
        }
        if (k <= dp[n - 1][m])
        {
            cout << 'a';
            --n;
        }
        else
        {
            cout << 'z';
            k -= dp[n - 1][m];
            --m;
        }
    }
    return 0;
}