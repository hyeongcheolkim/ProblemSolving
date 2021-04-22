//baekjoon ps 11053

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int res = 1;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n, 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        static int maxi;
        maxi = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                maxi = max(maxi, dp[j]+1);
        }
        dp[i] = maxi;
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}