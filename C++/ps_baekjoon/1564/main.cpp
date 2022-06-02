#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1e12;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    long long res = 1;
    cin >> n;
    for (int i = n; i >= 1; --i)
    {
        res *= i;
        while (res % 10 == 0)
            res /= 10;
        res %= MOD;
    }
    auto res_str = to_string(res);
    for_each(res_str.end() - 5, res_str.end(), [](auto& e) {cout << e; });
    return 0;
}