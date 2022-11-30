#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, res;
vector<vector<int>> dot;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dot.resize(n + 1, decltype(dot)::value_type(1, -INF));
    for (int i = 0; i < n; ++i)
    {
        int position, color;
        cin >> position >> color;
        dot[color].push_back(position);
    }
    for (int color = 1; color <= n; ++color)
    {
        auto& dots = dot[color];
        sort(dots.begin(), dots.end());
        dots.push_back(INF);
        for (int i = 1; i < dots.size() - 1; ++i)
            res += min(abs(dots[i - 1] - dots[i]), abs(dots[i] - dots[i + 1]));
    }
    cout << res;
    return 0;
}