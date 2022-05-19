#include <bits/stdc++.h>
using namespace std;

constexpr int T = 4;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = T;
    int x1, y1, p1, q1, x2, y2, p2, q2;
    while (t--)
    {
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
        int xl = max(x1, x2);
        int xr = min(p1, p2);
        int yb = max(y1, y2);
        int yt = min(q1, q2);
        int xd = xr - xl;
        int yd= yt - yb;
        if (xd > 0 && yd > 0)
            cout << 'a' << '\n';
        else if (xd < 0 || yd < 0)
            cout << 'd' << '\n';
        else if (xd == 0 && yd == 0)
            cout << 'c' << '\n';
        else
            cout << 'b' << '\n';
    }
    return 0;
}