//baekjoon ps 2624

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, k;
    cin >> t >> k;
    vector<int> dp(t + 1);
    dp[0] = 1;
    while (k--)
    {
        int cost, ea;
        cin >> cost >> ea;
        for (int idx = t; idx >= 0; --idx)
            for (int cnt = 1; cnt <= ea && 0 <= idx - cost * cnt; ++cnt)
                dp[idx] += dp[idx - cost * cnt];
    }
    cout << dp[t];
    return 0;
}