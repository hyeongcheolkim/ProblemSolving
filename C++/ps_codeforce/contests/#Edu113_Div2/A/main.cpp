#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> str(n + 1);
        vector<pair<int, int>> dp(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> str[i];
        for (int i = 1; i <= n; ++i)
        {
            if (str[i] == 'a')
            {
                dp[i].first += dp[i - 1].first + 1;
                dp[i].second += dp[i - 1].second;
            }
            else
            {
                dp[i].first += dp[i - 1].first;
                dp[i].second += dp[i - 1].second + 1;
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                if (flag)
                    break;
                int a = dp[j].first - dp[i - 1].first;
                int b = dp[j].second - dp[i - 1].second;
                if (a == b)
                {
                    cout << i << ' ' << j << '\n';
                    flag = true;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << -1 << ' ' << -1 << '\n';
    }
    return 0;
}