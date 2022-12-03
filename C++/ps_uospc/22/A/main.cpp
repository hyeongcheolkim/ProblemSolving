#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    if (m >= n * k)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}