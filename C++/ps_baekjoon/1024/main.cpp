#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, l;
    cin >> n >> l;
    for (int size = l; size <= 100; ++size)
    {
        double decimal = double(n) / double(size) - n / size;
        if (size % 2 == 0 && abs(decimal - 0.5) < 0.00001)
        {
            int lt = n / size;
            int rt = lt + 1;
            int len = size / 2;
            if (rt - len < 0)
                continue;
            for (int i = rt - len; i <= lt + len; ++i)
                cout << i << ' ';
            exit(0);
        }
        else if (size % 2 == 1 && abs(decimal) < 0.00001)
        {
            int mid = n / size;
            int len = (size - 1) / 2;
            if (mid - len < 0)
                continue;
            for (int i = mid - len; i <= mid + len; ++i)
                cout << i << ' ';
            exit(0);
        }
    }
    cout << -1;
    return 0;
}