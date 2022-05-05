#include <bits/stdc++.h>
using namespace std;

int n;
string pattern;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> pattern;
    auto fix = pattern | views::split('*') | views::transform([](auto e)
    {
        auto c = e | views::common;
        return string(c.begin(), c.end());
    });
    vector<string> vec{fix.begin(), fix.end()};
    auto prefix = vec.front();
    auto suffix = vec.back();
    reverse(suffix.begin(), suffix.end());
    while (n--)
    {
        string comp;
        cin >> comp;
        bool flag = true;
        if (prefix != comp.substr(0, prefix.size()))
            flag *= false;
        comp.erase(0, prefix.size());
        reverse(comp.begin(), comp.end());
        if (suffix != comp.substr(0, suffix.size()))
            flag *= false;
        if (flag)
            cout << "DA\n";
        else
            cout << "NE\n";
    }
    return 0;
}