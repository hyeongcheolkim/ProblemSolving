#include <bits/stdc++.h>
using namespace std;

int l, r;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> r;
    string str_l = to_string(l);
    string str_r = to_string(r);
    if (str_l.length() == str_r.length())
    {
        int mini = 0;
        for (int i = 0; i < str_l.length(); ++i)
        {
            if (str_l[i] != str_r[i])
                break;
            if (str_l[i] == '8' && str_r[i] == '8')
                ++mini;
        }
        cout << mini;
    }
    else
        cout << 0;
    return 0;
}