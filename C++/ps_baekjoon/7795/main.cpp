#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, cnt = 0;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];
        sort(b.begin(), b.end());
        for (const auto& e : a)
            cnt += lower_bound(b.begin(), b.end(), e) - b.begin();
        cout << cnt << '\n';
    }
    return 0;
}