#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull a, b, c;
unordered_map<ull, ull> cache;

ull solve(ull base, ull exp)
{
    if (auto iter = cache.find(exp); iter != cache.end())
        return iter->second;
    if (exp == 0)
        return cache[exp] = 1;
    if (exp == 1)
        return cache[exp] = base % c;
    if (exp % 2 == 1)
        return cache[exp] = ((solve(base, exp / 2) * solve(base, exp / 2)) % c * base) % c;
    return cache[exp] = (solve(base, exp / 2) * solve(base, exp / 2)) % c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    cout << solve(a, b);
    return 0;
}