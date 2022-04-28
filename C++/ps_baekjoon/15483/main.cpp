#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<vector<int>> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    dp.resize(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 0; i <= a.size(); ++i)
        dp[i][0] = i;
    for (int i = 0; i <= b.size(); ++i)
        dp[0][i] = i;
    for (int i = 1; i <= a.size(); ++i)
        for (int j = 1; j <= b.size(); ++j)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({
                dp[i - 1][j],
                dp[i][j - 1],
                dp[i - 1][j - 1],
                    }) + 1;
    cout << dp[a.size()][b.size()];
    return 0;
}