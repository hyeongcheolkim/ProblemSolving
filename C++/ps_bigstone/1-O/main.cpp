#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int num;
    while (cin >> num)
    {
        int val = 1;
        int len = 1;
        while (val % num != 0)
        {
            val %= num;
            val = 10 * val + 1;
            ++len;
        }
        cout << len << '\n';
    }
    return 0;
}