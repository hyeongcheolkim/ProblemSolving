#include <bits/stdc++.h>
using namespace std;

constexpr int mxD = 30;
int d, k, dp_first[mxD + 1], dp_second[mxD + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> d >> k;
    dp_first[1] = 1;
    dp_first[2] = 0;
    dp_second[1] = 0;
    dp_second[2] = 1;
    for (int i = 3; i <= 30; ++i)
    {
        dp_first[i] = dp_first[i - 1] + dp_first[i - 2];
        dp_second[i] = dp_second[i - 1] + dp_second[i - 2];
    }
    for (int f = 1; f <= k; ++f)
    {
        long long remain = k - f * dp_first[d];
        if (remain % dp_second[d] == 0)
        {
            cout << f << '\n';
            cout << remain / dp_second[d];
            exit(0);
        }
    }
    return 0;
}