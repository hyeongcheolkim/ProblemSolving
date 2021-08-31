#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n; ++i)
        res += a[i] * b[i];
    cout << res;
    return 0;
}