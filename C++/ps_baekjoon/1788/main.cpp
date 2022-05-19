#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9, INF = numeric_limits<int>::max() / 2;
vector<int> cache;
int n, SIZE;

int get_idx(int num) { return SIZE + num; }

int solve(int num)
{
    int& ret = cache[get_idx(num)];
    if (ret != INF)
        return ret;
    if (num == 0)
        return ret = 0;
    if (num == 1)
        return ret = 1;
    if (num >= 2)
        return ret = (solve(num - 1) + solve(num - 2)) % MOD;
    else
        return ret = (solve(num + 2) - solve(num + 1)) % MOD;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    fill(cache.begin(), cache.end(), INF);
    cin >> n;
    SIZE = abs(n);
    cache.resize(2 * SIZE + 1, INF);
    int res = solve(n);
    if (res > 0)
        cout << 1;
    else if (res < 0)
        cout << -1;
    else
        cout << 0;
    cout << '\n' << abs(res);
    return 0;
}