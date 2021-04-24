//baekjoon ps 1912

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int maxi;
    vector<int> arr(n);
    vector<int> dp(n,0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    maxi = dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
    return 0;
}