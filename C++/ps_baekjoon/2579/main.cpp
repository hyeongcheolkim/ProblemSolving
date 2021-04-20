//baekjoon ps 2579

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct score
{
    unsigned int point1;
    unsigned int point2;
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n + 1,0);
    vector<score> dp(n + 1);
    vector<char> dpcnt(n + 1,1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    dp[1].point1 = arr[1];
    dp[2].point1 = arr[2] + arr[1];
    dpcnt[2] = dpcnt[1] + 1;
    dp[2].point2 = arr[2];
    for (int i = 3; i <= n;i++)
    {
        if(dpcnt[i-1]==2)
        {
            dp[i].point1 = arr[i]+dp[i - 1].point2;
            dpcnt[i] = 1 + 1;
        }
        else
        {
            if(dp[i-1].point1>dp[i-1].point2)
            {
                dp[i].point1 = arr[i]+dp[i - 1].point1;
                dpcnt[i] = dpcnt[i-1] + 1;
            }
            else
            {
                dp[i].point1 = arr[i]+dp[i - 1].point2;
                dpcnt[i] = 1 + 1;
            }
            
        }
        dp[i].point2 = arr[i]+max(dp[i - 2].point1, dp[i - 2].point2);
    }
    cout << max(dp[n].point1, dp[n].point2);
    return 0;
}