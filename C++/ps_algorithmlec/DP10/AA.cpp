// cpp algorithm ps number DP10

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int money;
    cin >> n;
    vector<int> coin(n);
    for (int i = 0; i < n;i++)
        cin >> coin[i];
    cin >> money;
    vector<int> dp(money + 1, 10000);
    dp[0] = 0;
    for (int i = 0;i<coin.size();i++)
    {
        for (int x = coin[i]; x <= money;x++)
        {
            dp[x] = min(dp[x - coin[i]] + 1, dp[x]);
        }
    }
    cout << dp[money];
    return 0;
}