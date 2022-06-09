#include <bits/stdc++.h>
using namespace std;

constexpr int mxVal = 2e3;
int d1, d2, cnt;
bool vst[mxVal + 1][mxVal + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> d1 >> d2;
    for (int i = d1; i <= d2; ++i)
        for (int j = 1; j <= i; ++j)
        {
            int _gcd = gcd(i, j);
            int a = i / _gcd;
            int b = j / _gcd;
            if (vst[a][b])
                continue;
            vst[a][b] = true;
            ++cnt;
        }
    cout << cnt;
    return 0;
}