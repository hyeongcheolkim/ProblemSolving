#include <bits/stdc++.h>
using namespace std;
using circle = tuple<int, int, int>;
using pos = pair<int, int>;

constexpr int mxN = 5e1;
circle planet[mxN];

bool inCircle(const pos &p, const circle &c)
{
    auto [a, b] = p;
    auto [x, y, r] = c;
    if (sqrt(pow((x - a), 2) + pow(y - b, 2)) <= r)
        return true;
    else
        return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, res = 0;
        pos prince, rose;
        cin >> prince.first >> prince.second >> rose.first >> rose.second >> n;
        for (int i = 0; i < n; ++i)
            cin >> get<0>(planet[i]) >> get<1>(planet[i]) >> get<2>(planet[i]);
        for (int i = 0; i < n; ++i)
            if (inCircle(prince, planet[i]) ^ inCircle(rose, planet[i]))
                ++res;
        cout << res << '\n';
    }
    return 0;
}