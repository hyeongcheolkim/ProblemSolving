#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 3e5;
int XOR[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= mxN; ++i)
        XOR[i] = i ^ XOR[i - 1];
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, temp;
        cin >> a >> b;
        temp = XOR[a - 1];
        temp ^= b;
        if (temp == 0)
            cout << a << '\n';
        else if (temp == a)
            cout << a + 2 << '\n';
        else
            cout << a + 1 << '\n';
    }
    return 0;
}