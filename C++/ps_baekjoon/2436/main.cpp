#include <bits/stdc++.h>
using namespace std;

int _gcd, _lcm, res1, res2;

int divisor_counter(int val1, int val2)
{
    int ret = 0;
    for (long long i = 1; i * i <= min(val1, val2); ++i)
        if (val1 % i == 0 && val2 % i == 0)
            ++ret;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> _gcd >> _lcm;
    int complement = _lcm / _gcd;
    for (long long i = 1; i * i <= complement; ++i)
        if (complement % i == 0)
        {
            int j = complement / i;
            int divisor_cnt = divisor_counter(i, j);
            if (divisor_cnt < 2)
            {
                res1 = i * _gcd;
                res2 = j * _gcd;
            }
        }
    cout << res1 << ' ' << res2;
    return 0;
}