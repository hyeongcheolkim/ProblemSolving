#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5;
char bulb[mxN + 2];
int n, cnt = 0;

void change(int idx)
{
    bulb[idx] = (bulb[idx] == '0' ? '1' : '0');
    bulb[idx + 1] = (bulb[idx + 1] == '0' ? '1' : '0');
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> bulb[i];
    for (int i = 1; i < n; ++i)
        if (bulb[i] == '0')
        {
            change(i);
            ++cnt;
        }
    if (bulb[n] == '1')
        cout << cnt;
    else
        cout << -1;
    return 0;
}