#include <bits/stdc++.h>
using namespace std;

long long cnt;
int t, n, m;
vector<int> acc_a, acc_b, val_b;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    cin >> n;
    acc_a.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> acc_a[i];
        acc_a[i] += acc_a[i - 1];
    }
    cin >> m;
    acc_b.resize(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> acc_b[i];
        acc_b[i] += acc_b[i - 1];
    }
    val_b.reserve(m * m);
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < i; ++j)
            val_b.push_back(acc_b[i] - acc_b[j]);
    sort(val_b.begin(), val_b.end());
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
        {
            auto target = t - (acc_a[i] - acc_a[j]);
            if (binary_search(val_b.begin(), val_b.end(), target))
                cnt += upper_bound(val_b.begin(), val_b.end(), target) - lower_bound(val_b.begin(), val_b.end(), target);
        }
    cout << cnt;
    return 0;
}