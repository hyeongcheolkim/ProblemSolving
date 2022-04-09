#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;
vector<int> dp, step_size;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1, INF);
    dp[1] = 0;
    step_size.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> step_size[i];
    for (int i = 1; i <= n; ++i)
    {
        int size = step_size[i];
        for (int j = i + 1; j <= i + size && j <= n; ++j)
            dp[j] = min(dp[j], dp[i] + 1);
    }
    cout << (dp.back() == INF ? -1 : dp.back());
    return 0;
}