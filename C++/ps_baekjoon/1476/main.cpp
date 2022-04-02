#include <bits/stdc++.h>
using namespace std;

int E, S, M;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> E >> S >> M;
    long long year = 1;
    int e = 1, s = 1, m = 1;
    while (!(E == e && S == s && M == m))
    {
        e = e % 15 + 1;
        s = s % 28 + 1;
        m = m % 19 + 1;
        ++year;
    }
    cout << year;
    return 0;
}