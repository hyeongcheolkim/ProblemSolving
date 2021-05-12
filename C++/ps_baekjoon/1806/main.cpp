//baekjoon ps 1806

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long n, s;
    int res = INT_MAX;
    cin >> n >> s;
    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        static long long input;
        cin >> input;
        dp[i] = input + dp[i - 1];
    }
    int lt = 0, rt = 0;
    while (rt <= n)
    {
        static unsigned long long sum;
        sum = dp[rt] - dp[lt];
        if (sum < s)
            rt++;
        else
        {
            res = min(res, rt - lt);
            lt++;
        }
    }
    if (res == INT_MAX)
        cout << 0;
    else
        cout << res;
    return 0;
}