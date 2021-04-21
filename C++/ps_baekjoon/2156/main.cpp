//baekjoon ps 2156

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned int n;
    cin >> n;
    vector<unsigned long long> arr(n + 1);
    vector<unsigned long long> cnt1(n + 1);
    vector<unsigned long long> cnt2(n + 1);
    for (unsigned int i = 1; i <= n; i++)
        cin >> arr[i];
    cnt1[1] = arr[1];
    cnt1[0] = cnt2[0] = cnt2[1] = 0;
    unsigned long long res = cnt1[1];
    for (unsigned int i = 2; i <= n;i++)
    {
        static unsigned long long maxi = 0;
        maxi = max({maxi, cnt1[i - 2], cnt2[i - 2]});
        cnt1[i] = arr[i] + maxi;
        cnt2[i] = arr[i] + cnt1[i - 1];
        res = max({res, cnt1[i], cnt2[i]});
    }
    cout << res;
    return 0;
}