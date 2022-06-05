#include <bits/stdc++.h>
using namespace std;

string board, res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> board;
    int len = 0;
    auto check = [&]()->void {
        if ((len % 4) % 2 == 0)
        {
            int a_ea = len / 4;
            int b_ea = (len % 4) / 2;
            while (a_ea--)
                res.append("AAAA");
            while (b_ea--)
                res.append("BB");
            len = 0;
        }
        else
        {
            cout << -1;
            exit(0);
        }
    };
    for (const auto& e : board)
    {
        if (e == 'X')
            ++len;
        if (e == '.')
        {
            check();
            res.append(".");
        }
    }
    if (len != 0)
        check();
    cout << res;
    return 0;
}