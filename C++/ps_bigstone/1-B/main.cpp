#include <bits/stdc++.h>
using namespace std;

string str;
map<char, int> cnt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    for (const auto& c : str)
        ++cnt[c];
    for (char c = 'a'; c <= 'z'; ++c)
        cout << cnt[c] << ' ';
    return 0;
}