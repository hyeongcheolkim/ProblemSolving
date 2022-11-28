#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
    return 0;
}