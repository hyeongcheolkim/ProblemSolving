#include <bits/stdc++.h>
using namespace std;

int k, c;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> c;
    while (c--)
    {
        cout << [&] {
            int m, n;
            cin >> m >> n;
            int gap = abs(m - n);
            int remain = k - max(m, n);
            if (m == n)
                return 1;
            if (m < n)
            {
                if (gap - remain <= 1)
                    return 1;
                else
                    return 0;
            }
            else
            {
                if (gap - remain <= 2)
                    return 1;
                else
                    return 0;
            }
        }() << '\n';
    }
    return 0;
}