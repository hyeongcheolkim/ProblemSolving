#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;
using ds = pair<int, int>;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;
pos res;

pair<pos, pos> minmax(pos p, ds d)
{
    pos Pmax = {p.first + d.first, p.second + d.second};
    pos Pmin = {p.first - d.first, p.second - d.second};
    return {Pmin, Pmax};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    auto [preMin, preMax] = minmax(pos{x, y}, ds{w, h});
    res = preMin;
    --n;
    while (n--)
    {
        cin >> x >> y >> w >> h;
        auto [nowMin, nowMax] = minmax(pos{x, y}, ds{w, h});
        if (preMax.first < nowMin.first || preMax.second < nowMin.second
            || preMin.first > nowMax.first || preMin.second > nowMax.second)
        {
            cout << "impossible";
            exit(0);
        }
        preMin = {max(preMin.first, nowMin.first), max(preMin.second, nowMin.second)};
        preMax = {min(preMax.first, nowMax.first), min(preMax.second, nowMax.second)};
        res = preMin;
    }
    cout << res.first << ' ' << res.second;
    return 0;
}