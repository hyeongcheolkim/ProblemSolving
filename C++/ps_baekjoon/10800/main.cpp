#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int, int>> balls;
vector<int> acc_by_idx;
unordered_map<int, int> acc_by_color;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    balls.reserve(n);
    acc_by_idx.resize(n);
    for (int idx = 0; idx < n; ++idx)
    {
        int color, size;
        cin >> color >> size;
        balls.emplace_back(size, color, idx);
    }
    sort(balls.begin(), balls.end());
    for (const auto& [size, color, idx] : balls)
    {
        static int acc = 0, cur = 0, cur_size = 0, cur_color = 0, cur_idx = 0;
        while (tie(cur_size, cur_color, cur_idx) = balls[cur], cur_size < size)
        {
            acc += cur_size;
            acc_by_color[cur_color] += cur_size;
            ++cur;
        }
        acc_by_idx[idx] = acc - acc_by_color[color];
    }
    for (const auto& e : acc_by_idx)
        cout << e << '\n';
    return 0;
}