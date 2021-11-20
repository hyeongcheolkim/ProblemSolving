#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 5e3, INF = numeric_limits<int>::max() / 2;
int n, card[mxN + 1], dp[mxN + 1][mxN + 1], acc[mxN + 1];

int fnc(int left = 1, int right = n)
{
    int& ret = dp[left][right];
    if (dp[left][right] != INF)
        return ret;
    if (right - left == 1)
        return ret = card[left] + card[right];
    int m1 = (acc[right] - acc[left - 1]) - fnc(left + 2, right);
    int m2 = (acc[right] - acc[left - 1]) - fnc(left, right - 2);
    int m3 = (acc[right] - acc[left - 1]) - fnc(left + 1, right - 1);
    return ret = max({m1, m2, m3});
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = INF;
    for (int i = 1; i <= n; ++i)
    {
        cin >> card[i];
        acc[i] = card[i];
        acc[i] += acc[i - 1];
    }
    cout << fnc();
    return 0;
}