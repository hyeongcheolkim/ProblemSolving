//baekjoon ps 14002

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    int len = 1;
    cin >> n;
    vector<int> arr(n + 1), dp(n + 1, 1), res;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                len = max(len, dp[i]);
            }
    for (int i = dp.size() - 1; i >= 1; i--)
        if (dp[i] == len)
        {
            res.push_back(i);
            len--;
        }
    cout << res.size() << '\n';
    for_each(res.rbegin(), res.rend(), [&](const auto &e)
             { cout << arr[e] << ' '; });
    return 0;
}