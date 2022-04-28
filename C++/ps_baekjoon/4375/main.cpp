#include <bits/stdc++.h>
using namespace std;

int num;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> num, !cin.eof())
    {
        int multiple = 1;
        int len = 1;
        while (multiple % num)
        {
            ++len;
            multiple = multiple * 10 + 1;
            multiple %= num;
        }
        cout << len << '\n';
    }
    return 0;
}