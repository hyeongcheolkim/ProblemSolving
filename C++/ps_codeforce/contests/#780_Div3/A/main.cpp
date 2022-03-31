#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
            cout << 1 << '\n';
        else
            cout << a + 2 * b + 1 << '\n';
    }
    return 0;
}