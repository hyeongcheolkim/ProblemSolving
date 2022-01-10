#include <bits/stdc++.h>
using namespace std;
using Long = long long;

constexpr Long mxM = 1e3;
Long n, m, input, cnt[mxM + 1], res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    ++cnt[0];
    while (n--)
    {
        static Long sum = 0;
        cin >> input;
        sum += input;
        sum %= m;
        ++cnt[sum];
    }
    for (int i = 0; i < m; ++i)
        res += cnt[i] * (cnt[i] - 1) / 2;
    cout << res;
    return 0;
}