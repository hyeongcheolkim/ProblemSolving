#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, h, mini = numeric_limits<int>::max(), cnt = 0;
    cin >> n >> h;
    vector<int> arr1, arr2;
    arr1.reserve(n / 2);
    arr2.reserve(n / 2);
    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        if (i % 2 == 1)
            arr1.push_back(num);
        else
            arr2.push_back(num);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (int height = 1; height <= h; ++height)
    {
        auto iter1 = lower_bound(arr1.begin(), arr1.end(), height);
        auto iter2 = upper_bound(arr2.begin(), arr2.end(), h - height);
        int cnt1 = arr1.end() - iter1;
        int cnt2 = arr2.end() - iter2;
        if (cnt1 + cnt2 < mini)
        {
            mini = cnt1 + cnt2;
            cnt = 1;
        }
        else if (cnt1 + cnt2 == mini)
            ++cnt;
    }
    cout << mini << ' ' << cnt;
    return 0;
}