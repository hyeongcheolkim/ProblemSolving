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
        long long sum = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                sum += gcd(arr[i], arr[j]);
        cout << sum << '\n';
    }
    return 0;
}