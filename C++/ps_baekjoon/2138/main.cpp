#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, res = INF;
vector<char> bulb, target;

void _switch(int idx)
{
    for (int i = idx - 1; i <= idx + 1; ++i)
        bulb[i] = (bulb[i] == '0' ? '1' : '0');
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    bulb.resize(n + 2); target.resize(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> bulb[i];
    for (int i = 1; i <= n; ++i)
        cin >> target[i];
    auto tmp = bulb;
    int cnt = 0;
    for (int i = 2; i <= n; ++i)
        if (bulb[i - 1] != target[i - 1])
        {
            _switch(i);
            ++cnt;
        }
    if (bulb[n] != target[n])
        cnt = INF;
    res = min(res, cnt);
    swap(bulb, tmp);
    _switch(1);
    cnt = 1;
    for (int i = 2; i <= n; ++i)
        if (bulb[i - 1] != target[i - 1])
        {
            _switch(i);
            ++cnt;
        }
    if (bulb[n] != target[n])
        cnt = INF;
    res = min(res, cnt);
    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}