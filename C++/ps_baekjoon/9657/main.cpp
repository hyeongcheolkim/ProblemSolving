#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e3;
int n;
bool dp[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp[2] = true;
    for (int i = 5; i <= n; ++i)
    {
        vector<reference_wrapper<bool>> tmp{
            dp[i - 1], dp[i - 3], dp[i - 4]
        };
        if (!any_of(tmp.begin(), tmp.end(), [&](auto& e) {return dp[i] != e; }))
            dp[i] = !dp[i];
    }
    if (dp[n])
        cout << "CY";
    else
        cout << "SK";
    return 0;
}