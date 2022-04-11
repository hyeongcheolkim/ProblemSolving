#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long double mini = numeric_limits<long double>::infinity();
    int n, k;
    cin >> n >> k;
    vector<long long> acc(n + 1), acc_pow(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> acc[i];
        acc_pow[i] = acc[i] * acc[i];
        acc_pow[i] += acc_pow[i - 1];
        acc[i] += acc[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = k; i + j - 1 <= n; ++j)
        {
            long double ex_of_pow = (acc_pow[i + j - 1] - acc_pow[i - 1]) / (long double)j;
            long double pow_of_ex = pow((acc[i + j - 1] - acc[i - 1]) / (long double)j, 2);
            long double vx = ex_of_pow - pow_of_ex;
            long double deviation = sqrt(vx);
            mini = min(mini, deviation);
        }
    cout.precision(11);
    cout << fixed << mini;
    return 0;
}