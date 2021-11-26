#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 33554432;
bitset<mxN> bs;
int num;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> num)
    {
        if (!bs[num])
            cout << num << ' ';
        bs[num] = 1;
    }
    return 0;
}