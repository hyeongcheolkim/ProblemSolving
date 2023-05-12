#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> arr;

bool check(const int& len)
{
    long long cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += arr[i] / len;
    return m <= cnt;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int lt = 0;
    int rt = arr.back() + 1;
    while (lt + 1 < rt)
    {
        int mid = (lt + rt) / 2;
        if (check(mid))
            lt = mid;
        else
            rt = mid;
    }
    cout << lt;
    return 0;
}