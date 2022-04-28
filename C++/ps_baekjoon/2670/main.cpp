#include <bits/stdc++.h>
using namespace std;

int n;
long double maxi = 0.0;
vector<long double> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        long double num;
        cin >> num;
        dp[i] = max(num, num * dp[i - 1]);
        maxi = max(maxi, dp[i]);
    }
    cout << fixed << setprecision(3) << maxi;
    return 0;
}