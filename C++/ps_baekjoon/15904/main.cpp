#include <bits/stdc++.h>
using namespace std;

char buff;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string target = "UCPC";
    int cur = 0;
    while ((buff = cin.get()) != '\n')
        if (target[cur] == buff)
            ++cur;
    if (cur == target.size())
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";
    return 0;
}