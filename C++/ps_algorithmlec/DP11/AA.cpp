// cpp algorithm ps number DP11

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Q
{
    int time, score;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Q> data(n+1);
    for (int i = 1; i <= n;i++)
        cin >>  data[i].score >> data[i].time;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n;i++)
    {
        dp[i] = dp[i - 1];
        for (int x = data[i].time; x <= m;x++)
            dp[i][x] = max(dp[i][x], dp[i - 1][x - data[i].time] + data[i].score);
    }
    cout<< *max_element(dp[n].begin(), dp[n].end());
    return 0;
}