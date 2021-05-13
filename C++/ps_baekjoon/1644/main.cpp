//baekjoon ps 1644

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int cnt = 0;
    cin >> n;
    vector<bool> arr(n + 1, true);
    for (int i = 2; i * i <= n; i++)
        if (arr[i])
            for (int j = i + i; j <= n; j += i)
                arr[j] = false;
    vector<long long> dp;
    dp.reserve(n);
    dp.push_back(0);
    for (int i = 2; i <= n; i++)
        if (arr[i])
            dp.push_back(i);
    for (int i = 1; i < dp.size(); i++)
        dp[i] += dp[i - 1];
    int lt = dp.size() - 2;
    int rt = dp.size() - 1;
    while (0 <= lt)
    {
        int sum = dp[rt] - dp[lt];
        if (sum == n)
        {
            cnt++;
            rt--;
        }
        else if (sum > n)
            rt--;
        else if (sum < n)
            lt--;
    }
    cout << cnt;
    return 0;
}