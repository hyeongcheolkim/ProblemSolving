//baekjoon ps 2629

#include <iostream>
#include <vector>

using namespace std;

int main()
{
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
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (const auto &e : weight)
        for (int i = sum; i >= e; --i)
            dp[i] = dp[i] || dp[i - e];
    int m;
    cin >> m;
    while (m--)
    {
        bool flag = false;
        int marble;
        cin >> marble;
        for (int i = 0; i <= sum - marble; ++i)
            if (dp[i] && dp[i + marble])
            {
                flag = true;
                break;
            }
        cout << (flag ? 'Y' : 'N') << ' ';
    }
    return 0;
}