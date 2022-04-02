#include <bits/stdc++.h>
using namespace std;

constexpr long long mxX = 1'000'000'000;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long x, y;
    cin >> x >> y;
    int z = y * 100 / x;
    if (z >= 99)
    {
        cout << -1;
        exit(0);
    }
    int lt = 0, rt = mxX, res = -1;
    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;
        if (z < (y + mid) * 100 / (x + mid))
        {
            rt = mid - 1;
            res = mid;
        }
        else
            lt = mid + 1;
    }
    cout << res;
    return 0;
}