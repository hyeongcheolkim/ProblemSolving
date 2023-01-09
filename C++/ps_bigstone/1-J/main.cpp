#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        unordered_map<string, int> cnt;
        int n, res = 1;
        cin >> n;
        while (n--)
        {
            string name, category;
            cin >> name >> category;
            ++cnt[category];
        }
        for (const auto& [ignore, val] : cnt)
            res *= (val + 1);
        cout << res - 1 << '\n';
    }
    return 0;
}