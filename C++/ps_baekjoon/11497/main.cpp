#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n), arr1, arr2;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
        {
            if (i % 2 == 0)
                arr1.push_back(arr[i]);
            else
                arr2.push_back(arr[i]);
        }
        arr1.insert(arr1.end(), arr2.rbegin(), arr2.rend());
        int res = abs(arr1.front() - arr1.back());
        for (int i = 0; i < arr1.size() - 1; ++i)
            res = max(res, abs(arr1[i] - arr1[i + 1]));
        cout << res << '\n';
    }
    return 0;
}