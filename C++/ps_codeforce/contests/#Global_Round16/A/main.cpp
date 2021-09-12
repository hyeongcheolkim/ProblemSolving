#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int d = n - ceil(n / 2.0) + 1;
        cout << s / d << '\n';
    }
    return 0;
}