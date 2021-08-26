#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (l <= r / 2)
            cout << r % (r / 2 + 1) << '\n';
        else
            cout << r % l << '\n';
    }
    return 0;
}