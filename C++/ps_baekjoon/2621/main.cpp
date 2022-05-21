#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 5;
array<pair<char, int>, SIZE> cards;

int solve()
{
    const auto& [c1, n1] = cards[0];
    const auto& [c2, n2] = cards[1];
    const auto& [c3, n3] = cards[2];
    const auto& [c4, n4] = cards[3];
    const auto& [c5, n5] = cards[4];
    unordered_map<int, int> cnt, cnt_reverse;

    bool color_all_same = c1 == c2 && c2 == c3 && c3 == c4 && c4 == c5;
    auto [mini, maxi] = minmax({n1, n2, n3, n4, n5});
    for (const auto& e : {n1, n2, n3, n4, n5})
        ++cnt[e];
    for (const auto& [num, ea] : cnt)
        cnt_reverse[ea] = num;

    bool num_continuos = [&] {
        bool ret = true;
        for (int i = mini; i < mini + 5; ++i)
            ret *= cnt[i];
        return ret;
    }();
    bool four_card = any_of(cnt.begin(), cnt.end(), [](auto& e) {
        return e.second == 4;
    });
    bool three_card = any_of(cnt.begin(), cnt.end(), [](auto& e) {
        return e.second == 3;
    });
    bool two_card = count_if(cnt.begin(), cnt.end(), [](auto& e) {
        return e.second == 2;
    }) == 1;
    bool two_pair = count_if(cnt.begin(), cnt.end(), [](auto& e) {
        return e.second == 2;
    }) == 2;

    if (color_all_same && num_continuos)
        return 900 + maxi;
    if (four_card)
        return 800 + cnt_reverse[4];
    if (three_card && two_card)
        return 700 + cnt_reverse[3] * 10 + cnt_reverse[2];
    if (color_all_same)
        return 600 + maxi;
    if (num_continuos)
        return 500 + maxi;
    if (three_card)
        return 400 + cnt_reverse[3];
    if (two_pair)
        return 300 + [&] {
        vector<int> tmp;
        for (const auto& [num, ea] : cnt)
            if (ea == 2)
                tmp.push_back(num);
        const auto& [mini, maxi] = minmax({tmp.front(), tmp.back()});
        return maxi * 10 + mini;
    }();
    if (two_card)
        return 200 + cnt_reverse[2];
    return 100 + maxi;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < SIZE; ++i)
        cin >> cards[i].first >> cards[i].second;
    cout << solve();
    return 0;
}