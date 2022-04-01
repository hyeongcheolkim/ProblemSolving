#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    char buff;
    int acc = 0;
    vector<int> number(10);
    while ((buff = cin.get()) != '\n')
    {
        ++number[buff - '0'];
        acc += buff - '0';
    }
    if (!number[0] || acc % 3 != 0)
        cout << -1;
    else
        for (int i = 9; i >= 0; --i)
            while (number[i]--)
                cout << i;
    return 0;
}