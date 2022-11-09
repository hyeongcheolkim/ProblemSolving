#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1, sum = 0; sum <= n; ++i)
    {
        sum += i;
        if (int remain = n - sum; remain >= 0 && remain % i == 0)
            ++cnt;
    }
    cout << cnt;
    return 0;
}