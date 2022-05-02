#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
            continue;
        int diff = arr[i + 1] - arr[i] + 1;
        arr[i + 1] -= diff;
        cnt += diff;
    }
    cout << cnt;
    return 0;
}