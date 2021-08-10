//baekjoon ps 2629

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max() / 2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0;
    cin >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i];
        sum += weight[i];
    }
    vector<int> dp(sum + 1, INF);
    dp[0] = 0;
    for (const auto &e : weight)
        for (int i = sum; i >= e; --i)
            dp[i] = min(dp[i], dp[i - e] + 1);
    int m;
    cin >> m;
    while (m--)
    {
        bool flag = false;
        int marble;
        cin >> marble;
        for (int i = 0; i <= sum - marble; ++i)
            if (dp[i] != INF && dp[i + marble] != INF)
            {
                flag = true;
                break;
            }
        cout << (flag ? 'Y' : 'N') << ' ';
    }
    return 0;
}