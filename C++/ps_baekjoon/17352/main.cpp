#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 3e5;
int n, uf[mxN + 1];

int find(int num)
{
    if (uf[num] == num)
        return num;
    return uf[num] = find(uf[num]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        uf[b] = a;
}

bool isUni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return true;
    else
        return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        uf[i] = i;
    for (int i = 0; i < n - 2; ++i)
    {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }
    for (int i = 2; i <= n; ++i)
        if (!isUni(1, i))
        {
            cout << 1 << ' ' << i;
            break;
        }
    return 0;
}