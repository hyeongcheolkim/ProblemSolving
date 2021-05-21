//baekjoon ps 11659

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    auto dp = new unsigned long long [n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << '\n';
    }
    delete[] dp;
    return 0;
}