#include <bits/stdc++.h>
using namespace std;

int m, n, cnt;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int lt = 0, rt = n - 1;
    while (lt < rt)
    {
        int sum = arr[lt] + arr[rt];
        if (sum == m)
        {
            ++cnt;
            ++lt;
        }
        else if (sum < m)
            ++lt;
        else if (sum > m)
            --rt;
    }
    cout << cnt;
    return 0;
}