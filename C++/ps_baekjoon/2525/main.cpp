#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + (b + c) / 60) % 24 << ' ' << (b + c) % 60;
    return 0;
}