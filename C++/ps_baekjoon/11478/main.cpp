#include <bits/stdc++.h>
using namespace std;

int cnt;
string word;
unordered_map<string, bool> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> word;
    for (int i = 0; i < word.size(); ++i)
        for (int len = 1; len <= word.length() - i; ++len)
        {
            string tmp = word.substr(i, len);
            if (vst[tmp])
                continue;
            vst[tmp] = true;
            ++cnt;
        }
    cout << cnt;
    return 0;
}