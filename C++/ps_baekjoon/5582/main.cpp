#include <bits/stdc++.h>
using namespace std;

int res = 0;
string s1, s2;
vector<vector<int>> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s1 >> s2;
    dp.resize(s1.size() + 1, vector<int>(s2.size() + 1));
    for (int i = 1; i <= s1.size(); ++i)
        for (int j = 1; j <= s2.size(); ++j)
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
    cout << res;
    return 0;
}