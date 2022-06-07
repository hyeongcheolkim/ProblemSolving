#include <bits/stdc++.h>
using namespace std;

int col, row, n;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> col >> row >> n;
    vector<int> c{0, col}, r{0, row};
    while (n--)
    {
        int direction, num;
        cin >> direction >> num;
        if (direction == 0)
            r.push_back(num);
        else
            c.push_back(num);
    }
    sort(c.begin(), c.end());
    sort(r.begin(), r.end());
    int r_max = 0, c_max = 0;
    for (int i = 0; i < c.size() - 1; ++i)
        c_max = max(c_max, c[i + 1] - c[i]);
    for (int i = 0; i < r.size() - 1; ++i)
        r_max = max(r_max, r[i + 1] - r[i]);
    cout << r_max * c_max;
    return 0;
}