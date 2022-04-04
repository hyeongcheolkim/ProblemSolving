#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1000;
int acc_sum[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int num = 1, cnt = 0;
    for (int i = 1; i <= mxN; ++i)
    {
        acc_sum[i] = acc_sum[i - 1] + num;
        if (++cnt == num)
        {
            ++num;
            cnt = 0;
        }
    }
    int a, b;
    cin >> a >> b;
    cout << acc_sum[b] - acc_sum[a - 1];
    return 0;
}