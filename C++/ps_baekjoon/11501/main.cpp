#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxi = 0;
        long long sum = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        reverse(arr.begin(), arr.end());
        for (const auto& e : arr)
        {
            if (maxi > e)
                sum += maxi - e;
            else
                maxi = e;
        }
        cout << sum << '\n';
    }
    return 0;
}