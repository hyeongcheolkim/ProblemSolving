#include <bits/stdc++.h>
using namespace std;

string str;
regex re{"(100+1+|01)+"};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    if (regex_match(str, re))
        cout << "SUBMARINE";
    else
        cout << "NOISE";
    return 0;
}