#include <bits/stdc++.h>
using namespace std;

int n, area, max_height;
vector<pair<int, int>> arr;

int solve()
{
    stack<pair<int, int>> s;
    for (const auto& [idx, height] : arr)
    {
        if (s.empty())
        {
            s.emplace(idx, height);
            continue;
        }
        if (s.top().second < height)
        {
            area += abs(idx - s.top().first) * (s.top().second);
            s.pop();
            s.emplace(idx, height);
        }
    }
    max_height = max(max_height, s.top().second);
    return s.top().first;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    int left_max_height_idx = solve();
    reverse(arr.begin(), arr.end());
    int right_max_height_idx = solve();
    int max_square_width = right_max_height_idx - left_max_height_idx + 1;
    cout << area + abs(max_square_width) * max_height;
    return 0;
}