#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e4;
int n, m, k, money[mxN + 1], uf[mxN + 1];

int find(int num)
{
    if (uf[num] == -1)
        return num;
    return uf[num] = find(uf[num]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (money[a] < money[b])
        uf[b] = a;
    else
        uf[a] = b;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    memset(uf, -1, sizeof(uf));
    for (int i = 1; i <= n; ++i)
        cin >> money[i];
    while (m--)
    {
        int v, w;
        cin >> v >> w;
        uni(v, w);
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        if (uf[i] == -1)
            sum += money[i];
    if (sum <= k)
        cout << sum;
    else
        cout << "Oh no";
    return 0;
}