#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    dp.resize(n + 1);
    iota(dp.begin(), dp.end(), 0);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = n; i >= 0; --i)
            dp[i] = min(dp[i], dp[max(i - a - b, 0)] + a);
    }
    cout << dp[n];
    return 0;
}