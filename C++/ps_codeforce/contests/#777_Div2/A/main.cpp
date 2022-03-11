#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        string res;
        int n;
        cin >> n;
        int quotient = n / 3;
        int remainder = n % 3;
        while (quotient--)
            res.append("21");
        if (remainder == 1)
            res = "1" + res;
        if (remainder == 2)
            res.append("2");
        cout << res << '\n';
    }
    return 0;
}