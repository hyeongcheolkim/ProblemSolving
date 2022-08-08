#include <bits/stdc++.h>
using namespace std;

int n;
string str;
const regex re{R"((100+1+|01)+)"};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        cin >> str;
        cout << (regex_match(str, re) ? "YES\n" : "NO\n");
    }
    return 0;
}