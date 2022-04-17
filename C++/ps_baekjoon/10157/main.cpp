#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{+1, 0, -1, 0}, dc[]{0, +1, 0, -1};
int c, r, k;
vector<vector<bool>> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> r >> k;
    if (k > r * c)
    {
        cout << 0;
        exit(0);
    }
    vst.resize(r + 2, vector<bool>(c + 2));
    int row = 1, col = 1, direction = 0;
    vst[row][col] = true;
    while (--k)
    {
        int next_row = row + dr[direction];
        int next_col = col + dc[direction];
        if (!(1 <= next_row && next_row <= r && 1 <= next_col && next_col <= c) || vst[next_row][next_col])
        {
            ++direction;
            direction %= 4;
            next_row = row + dr[direction];
            next_col = col + dc[direction];
        }
        row = next_row;
        col = next_col;
        vst[row][col] = true;
    }
    cout << col << ' ' << row;
    return 0;
}