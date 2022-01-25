#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 3e2, mxM = 2e1;
int n, m, table[mxN + 1][mxM + 1], trace[mxN + 1][mxM + 1], cache[mxN + 1][mxM + 1];

void chase(int cost = n, int company = m)
{
    if (company == 0)
        return;
    chase(cost - trace[cost][company], company - 1);
    cout << trace[cost][company] << ' ';
}

int solve(int cost = n, int company = m)
{
    if (company == 0)
        return 0;
    int& ret = cache[cost][company];
    if (ret != -1)
        return ret;
    for (int k = 0; k <= cost; ++k)
        if (int val = solve(cost - k, company - 1) + table[k][company]; ret < val)
        {
            ret = val;
            trace[cost][company] = k;
        }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int invest;
        cin >> invest;
        for (int j = 1; j <= m; ++j)
            cin >> table[invest][j];
    }
    cout << solve() << '\n';
    chase();
    return 0;
}