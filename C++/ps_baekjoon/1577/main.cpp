#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mxNM = 100;
ll n, m, k, cache[mxNM + 1][mxNM + 1];
bool block[mxNM + 1][mxNM + 1][2];
enum { DOWN_BLOCKED, LEFT_BLOCKED };

ll dp(int row, int col)
{
    if (!(0 <= row && row <= n && 0 <= col && col <= m))
        return 0;
    auto& ret = cache[row][col];
    if (ret != -1)
        return ret;
    if (row == 0 && col == 0)
        return ret = 1;
    ret = 0;
    if (block[row][col][LEFT_BLOCKED] && block[row][col][DOWN_BLOCKED])
        return ret = 0;
    else if (block[row][col][LEFT_BLOCKED])
        return ret += dp(row - 1, col);
    else if (block[row][col][DOWN_BLOCKED])
        return ret += dp(row, col - 1);
    else
        return ret += dp(row - 1, col) + dp(row, col - 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    memset(cache, -1, sizeof(cache));
    while (k--)
    {
        int r0, c0, r1, c1;
        cin >> r0 >> c0 >> r1 >> c1;
        pair<int, int> p0{r0, c0}, p1{r1, c1};
        auto [mini, maxi] = minmax(p0, p1);
        if (maxi.first == mini.first)
            block[maxi.first][maxi.second][LEFT_BLOCKED] = true;
        else
            block[maxi.first][maxi.second][DOWN_BLOCKED] = true;
    }
    cout << dp(n, m);
    return 0;
}