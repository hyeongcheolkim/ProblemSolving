#include <bits/stdc++.h>
using namespace std;

int cnt[2];
char buff, back = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while ((buff = cin.get()) != '\n')
        if (back != buff)
        {
            back = buff;
            ++cnt[buff - '0'];
        }
    cout << min(cnt[0], cnt[1]);
    return 0;
}