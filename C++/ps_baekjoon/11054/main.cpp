//baekjoon ps 11054

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
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
    {
        static int maxi;
        maxi = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                maxi = max(maxi, dp1[j] + 1);
        dp1[i] = maxi;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        static int maxi;
        maxi = 1;
        for (int j = n - 1; i < j; j--)
            if (arr[i] > arr[j])
                maxi = max(maxi, dp2[j] + 1);
        dp2[i] = maxi;
    }
    for (int i = 0; i < n; i++)
        res = max(res, dp1[i] + dp2[i]-1);
    cout << res;
    return 0;
}