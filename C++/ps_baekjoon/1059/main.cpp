#include <bits/stdc++.h>
using namespace std;

int l, n, cnt;
array<bool, 1000 + 1> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> l;
    while (l--)
    {
        int num;
        cin >> num;
        vst[num] = true;
    }
    cin >> n;
    int lt = n, rt = n;
    while (lt >= 1 && !vst[lt])
        --lt;
    while (rt <= 1000 && !vst[rt])
        ++rt;
    if (lt == rt)
    {
        cout << 0;
        exit(0);
    }
    ++lt;
    --rt;
    cout << (n - lt) * (rt - n + 1) + (rt - n);
    return 0;
}