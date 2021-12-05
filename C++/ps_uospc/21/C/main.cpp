#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5;
int n, bulb[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> bulb[i];
    int cnt = 0;
    int maxi = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (bulb[i] == 0)
            ++cnt;
        else
        {
            maxi = max(maxi, cnt);
            cnt = 0;
        }
    }
    maxi = max(maxi, cnt);
    if (bulb[1] == 0 && bulb[n] == 0)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (bulb[i] == 0)
                ++cnt1;
            else
                break;
        }
        for (int i = n; i >= 1; --i)
        {
            if (bulb[i] == 0)
                ++cnt2;
            else
                break;
        }
        maxi = max(maxi, cnt1 + cnt2);
    }
    if (maxi >= n)
        cout << 0;
    else
        cout << (n - maxi - 1);
    return 0;
}