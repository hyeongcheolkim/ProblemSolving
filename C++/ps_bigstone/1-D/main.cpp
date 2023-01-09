#include <bits/stdc++.h>
using namespace std;

string str, r_str;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    r_str.resize(str.size());
    reverse_copy(str.begin(), str.end(), r_str.begin());
    cout << (str == r_str);
    return 0;
}