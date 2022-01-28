#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    dp.assign(n + 1, -1);
    dp[0] = 0;
    while (k--)
    {
        int importance, time;
        cin >> importance >> time;
        for (int idx = n; idx >= time; --idx)
            if (dp[idx - time] != -1)
                dp[idx] = max(dp[idx], dp[idx - time] + importance);
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}