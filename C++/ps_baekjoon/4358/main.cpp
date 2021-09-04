#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(4);
    cout << fixed;
    map<string, int> tree;
    int total = 0;
    string str;
    while (getline(cin, str))
    {
        ++tree[str];
        ++total;
    }
    for (const auto &e : tree)
    {
        auto [name, ea] = e;
        cout << name << ' ' << static_cast<double>(ea) / total * 100.0 << '\n';
    }
    return 0;
}