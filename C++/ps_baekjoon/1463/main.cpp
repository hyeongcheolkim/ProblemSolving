//baekjoon ps 1463

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned int x;
    cin >> x;
    vector<char> dp(x+1,0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 3;
    dp[6] = 2;
    dp[7] = 3;
    dp[8] = 3;
    dp[9] = 2;
    dp[10] = 3;
    for (unsigned int i = 11; i <= x; i++)
    {
        if(i%6==0)
            dp[i] = min({dp[i / 2] + 1,dp[i / 3] + 1,dp[i - 1] + 1});
        else if(i%2==0)
            dp[i] = min(dp[i / 2] + 1,dp[i - 1] + 1);
        else if(i%3==0)
            dp[i] = min(dp[i / 3] + 1,dp[i - 1] + 1);
        else
            dp[i] = dp[i - 1] + 1;
    }
cout << (int)dp[x];
return 0;
}