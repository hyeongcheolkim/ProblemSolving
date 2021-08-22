//baekjoon ps 1947

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
constexpr ull DIVIDER = 1'000'000'000;
ull cache[1'000'000 + 1];

int complete_permutation(ull num)
{
    if (num == 1)
        return 0;
    if (num == 2)
        return 1;
    if (cache[num] != 0)
        return cache[num];
    return cache[num] = ((num - 1) * (complete_permutation(num - 1) + complete_permutation(num - 2)) % DIVIDER) % DIVIDER;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull n;
    cin >> n;
    cout << complete_permutation(n);
    return 0;
}