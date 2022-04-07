#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    vector<string> prefix;
    prefix.reserve(s.size());
    for (int i = 0; i < s.size(); ++i)
        prefix.push_back(s.substr(i, s.size() - i));
    sort(prefix.begin(), prefix.end());
    for (const auto& e : prefix)
        cout << e << '\n';
    return 0;
}