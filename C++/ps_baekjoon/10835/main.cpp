#include <bits/stdc++.h>
using namespace std;

int n, maxi;
vector<int> lt, rt;
vector<vector<int>> cache;

int dp(int left, int right)
{
    int& ret = cache[left][right];
    if (ret != -1)
        return ret;
    if (left == 0 || right == 0)
        return ret = 0;
    ret = max(ret, dp(left - 1, right));
    ret = max(ret, dp(left - 1, right - 1));
    if (lt[left] > rt[right])
        ret = max(ret, dp(left, right - 1) + rt[right]);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    lt.resize(n + 1);
    rt.resize(n + 1);
    cache.resize(n + 1, vector<int>(n + 1, -1));
    for (int i = n; i >= 1; --i)
        cin >> lt[i];
    for (int i = n; i >= 1; --i)
        cin >> rt[i];
    cout << dp(n, n);
    return 0;
}