#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2, mxN= 2e5;
int arr[mxN + 1], dp[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, t, query, p, q, x, y, cnt = 0;
    cin >> n >> t;
    arr[0] = INF;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] < arr[i - 1])
            dp[i] = 1;
        else
            dp[i] = dp[i - 1] + 1;
    }
    while (t--)
    {
        cin >> query;
        switch (query)
        {
        case 1:
            cin >> x >> y;
            arr[x] = y;
            if (arr[x] < arr[x - 1])
                dp[x] = 1;
            else
                dp[x] = dp[x - 1] + 1;
            for (int i = x + 1; i <= n; ++i)
            {
                int temp = dp[i];
                if (arr[i] < arr[i - 1])
                    dp[i] = 1;
                else
                    dp[i] = dp[i - 1] + 1;
                if (temp == dp[i])
                    break;
            }
            break;
        case 2:
            cnt = 0;
            cin >> p >> q;
            int idx = p, temp = 0;
            while (idx <= q && dp[idx] != 1)
                ++idx;
            for (int i = p; i < idx; ++i)
                temp += dp[i];
            temp -= (dp[p] - 1) * (idx - p);
            cnt += temp;
            for (int i = idx; i <= q; ++i)
                cnt += dp[i];
            cout << cnt << '\n';
            break;
        }
    }
    return 0;
}