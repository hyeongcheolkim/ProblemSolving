#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    int lt = 1;
    int rt = 1;
    int sum = arr[1];
    while (rt <= n)
        if (sum < m)
            sum += arr[++rt];
        else if (sum > m)
        {
            sum -= arr[lt++];
            if (lt > rt)
                sum = arr[rt = lt];
        }
        else if (sum == m)
        {
            ++cnt;
            sum -= arr[lt++];
        }
    cout << cnt;
    return 0;
}