#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr ull mod = 998244353;
constexpr int mxN = 2e5;
ull memo[mxN + 1];

ull permutation(ull num)
{
    if (num == 1 || num == 0)
        return 1;
    if (memo[num] != 0)
        return memo[num];
    return memo[num] = (num * (permutation(num - 1))) % mod;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> num;
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            int input;
            cin >> input;
            ++num[input];
        }
        auto iter = num.end();
        if (num.size() >= 2)
        {
            auto [first, ea_f] = *--iter;
            auto [second, ea_s] = *--iter;
            if (first - second > 1)
                cout << 0 << '\n';
            else
                cout << permutation(n) - ea_f * permutation(n - 1) << '\n';
        }
        else
            cout << permutation(n) << '\n';
    }
    return 0;
}