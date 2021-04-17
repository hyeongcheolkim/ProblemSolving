// cpp algorithm ps number DP05

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int res = INT_MIN;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n,0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0] = 1;
    for (int index = 1; index < n; index++)
    {
        static int max;
        max = 0;
        for (int i = 0; i < index; i++)
        {
            if (arr[i]<arr[index] && dp[i] > max)
                max = dp[i];
        }
        dp[index] = max + 1;
        if(max+1>res)
            res = max + 1;
    }
    cout << res;

    return 0;
}