//baekjoon ps 9461

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        static int input;
        cin >> input;
        unsigned long long dp[105];
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        dp[6] = 3;
        dp[7] = 4;
        dp[8] = 5;
        for (int i = 9; i <= input; i++)
            dp[i] = dp[i - 5] + dp[i - 1];
        cout << dp[input]<<'\n';
    }

    return 0;
}