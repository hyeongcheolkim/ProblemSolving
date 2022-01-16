#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull res, n;
array<ull, 6> dice;
unordered_map<int, ull> viewable_num;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < 6; ++i)
        cin >> dice[i];
    if (n == 1)
    {
        sort(dice.begin(), dice.end());
        cout << accumulate(dice.begin(), dice.end() - 1, 0);
        return 0;
    }
    for (int i = 0; i < 3; ++i)
        dice[i] = min(dice[i], dice[5 - i]);
    sort(dice.begin(), dice.begin() + 3);
    viewable_num[1] = (n - 1) * (n - 2) * 4 + pow((n - 2), 2);
    viewable_num[2] = 8 * (n - 2) + 4;
    viewable_num[3] = 8 - 4;
    for (const auto& [viewable, ea] : viewable_num)
        for (int i = 0; i < viewable; ++i)
            res += dice[i] * ea;
    cout << res;
    return 0;
}