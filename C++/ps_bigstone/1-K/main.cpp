#include <bits/stdc++.h>
using namespace std;

string str, res;
map<char, int> cnt;
char odd_c;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    for (const auto& c : str)
        ++cnt[c];
    for (const auto& [key, val] : cnt)
    {
        for (int i = 0; i < val / 2; ++i)
            res.push_back(key);
        if (val % 2 != 0 && odd_c != 0)
        {
            cout << "I'm Sorry Hansoo";
            exit(0);
        }
        if (val % 2 != 0 && odd_c == 0)
        {
            odd_c = key;
        }
    }
    cout << res;
    reverse(res.begin(), res.end());
    if (odd_c != 0)
        cout << odd_c;
    cout << res;
    return 0;
}