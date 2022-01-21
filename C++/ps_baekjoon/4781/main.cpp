#include <bits/stdc++.h>
using namespace std;

constexpr int mxM = 100;
int n, dp[mxM * 100 + 5];
double m;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> m, !(n == 0 && m == 0.0))
    {
        memset(dp, 0, sizeof(dp));
        int M = static_cast<int>(m * 100.0 + 0.5);
        while (n--)
        {
            int c;
            double p;
            cin >> c >> p;
            int P = static_cast<int>(p * 100.0 + 0.5);
            for (int idx = P; idx <= M; ++idx)
                dp[idx] = max(dp[idx], dp[idx - P] + c);
        }
        cout << dp[M] << '\n';
    }
    return 0;
}