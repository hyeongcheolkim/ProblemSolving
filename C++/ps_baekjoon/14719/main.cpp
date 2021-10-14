#include <bits/stdc++.h>
using namespace std;

constexpr int mxH = 5e2, mxW = 5e2;
int h, w, res = 0, block[mxW + 1];
bool board[mxH + 1][mxW + 1];
stack<int> s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w;
    for (int i = 1; i <= w; ++i)
        cin >> block[i];
    for (int col = 1; col <= w; ++col)
        for (int row = h - block[col] + 1; row <= h; ++row)
            board[row][col] = true;
    for (int row = h; row >= 1; --row)
    {
        while (!s.empty())
            s.pop();
        for (int col = 1; col <= w; ++col)
            if (board[row][col])
            {
                if (!s.empty())
                {
                    res += col - s.top() - 1;
                    s.pop();
                }
                s.push(col);
            }
    }
    cout << res;
    return 0;
}