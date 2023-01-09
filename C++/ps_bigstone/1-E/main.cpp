#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<char, int> cnt;
string res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        string name;
        cin >> name;
        ++cnt[name.front()];
    }
    for (char c = 'a'; c <= 'z'; ++c)
        if (cnt[c] >= 5)
            res.push_back(c);
    if (res.empty())
        cout << "PREDAJA";
    else
        cout << res;
    return 0;
}