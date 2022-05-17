#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 1e8;
bitset<SIZE + 1> bs;

int a, b;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    while (a--)
    {
        int num;
        cin >> num;
        bs[num] = !bs[num];
    }
    while (b--)
    {
        int num;
        cin >> num;
        bs[num] = !bs[num];
    }
    cout << bs.count();
    return 0;
}