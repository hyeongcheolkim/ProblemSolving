#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int x;
    cin >> x;
    bitset<10> bs{x};
    cout << bs.count();
    return 0;
}