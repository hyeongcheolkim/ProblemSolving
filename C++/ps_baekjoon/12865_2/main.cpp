#include <bits/stdc++.h>
using namespace std;

int n, k;
int answer = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    vector<int> dp(k + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int w, v;
        cin >> w >> v;

        for (int i = k; i - w >= 0; --i)
        {
            if (dp[i - w] == -1)
                continue;
            dp[i] = max(dp[i - w] + v, dp[i]);
            answer = max(answer, dp[i]);
        }
    }
    cout << answer;
    return 0;
}