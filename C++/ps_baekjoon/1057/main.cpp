#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, n0, n1, round = 0;
    cin >> n >> n0 >> n1;
    while (n0 != n1)
    {
        n0 = n0 - n0 / 2;
        n1 = n1 - n1 / 2;
        ++round;
    }
    cout << round;
    return 0;
}