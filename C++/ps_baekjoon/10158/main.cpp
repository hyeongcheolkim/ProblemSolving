#include <bits/stdc++.h>
using namespace std;

int w, h, p, q, t;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> w >> h >> p >> q >> t;
    int row_max = h, col_max = w, row = q, col = p;
    row = (row + t) % (row_max * 2);
    col = (col + t) % (col_max * 2);
    row = row_max - abs(row_max - row);
    col = col_max - abs(col_max - col);
    cout << col << ' ' << row;
    return 0;
}