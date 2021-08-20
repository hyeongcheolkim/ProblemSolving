//baekjoon ps 5557

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, length, total;
    cin >> n;
    length = n - 1;
    vector<int> arr(length + 1);
    vector<vector<long long>> dp(length + 1, vector<long long>(21));
    for (int i = 1; i <= length; ++i)
        cin >> arr[i];
    cin >> total;
    ++dp[1][arr[1]];
    for (int idx = 2; idx <= length; ++idx)
        for (int pre_num = 0; pre_num <= 20; ++pre_num)
            if (auto &pre_cnt = dp[idx - 1][pre_num]; pre_cnt)
            {
                if (pre_num + arr[idx] <= 20)
                    dp[idx][pre_num + arr[idx]] += pre_cnt;
                if (pre_num - arr[idx] >= 0)
                    dp[idx][pre_num - arr[idx]] += pre_cnt;
            }
    cout << dp[length][total];
    return 0;
}