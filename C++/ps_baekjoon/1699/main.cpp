#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;
vector<int> dp;

int main()
{
    cin >> n;
    dp.resize(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= static_cast<int>(sqrt(n)); ++i)
    {
        int step_size = i * i;
        for (int idx = step_size; idx <= n; ++idx)
            dp[idx] = min(dp[idx], dp[idx - step_size] + 1);
    }
    cout << dp.back();
    return 0;
}