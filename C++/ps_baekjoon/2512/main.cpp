#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, acc, res;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> m;
    sort(arr.begin(), arr.end());
    int lt = 0;
    int rt = arr.back();
    while (lt <= rt)
    {
        int acc = 0;
        int mid = (lt + rt) / 2;
        for (const auto& e : arr)
            acc += min(e, mid);
        if (m >= acc)
        {
            res = mid;
            lt = mid + 1;
        }
        else
            rt = mid - 1;
    }
    cout << res;
    return 0;
}