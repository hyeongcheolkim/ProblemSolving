#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, INF = numeric_limits<int>::max() / 2;
int n, total_population, res = INF;
vector<vector<int>> population;

int population_difference(const int& x, const int& y, const int& d1_maxi, const int& d2_maxi)
{
    vector<pair<int, int>> left_up, right_up, left_down, right_down;
    vector<vector<int>> area(n + 2, vector<int>(n + 2, 5));
    unordered_map<int, int> area_population;
    for (int d1 = 0; d1 <= d1_maxi; ++d1)
    {
        left_up.emplace_back(x + d1, y - d1);
        right_down.emplace_back(x + d2_maxi + d1, y + d2_maxi - d1);
    }
    for (int d2 = 0; d2 <= d2_maxi; ++d2)
    {
        left_down.emplace_back(x + d2, y + d2);
        right_up.emplace_back(x + d1_maxi + d2, y - d1_maxi + d2);
    }
    for (const auto& [col, row] : left_up)
    {
        for (int i = 1; i < row; ++i)
            for (int j = 1; j <= col; ++j)
                area[i][j] = 1;
    }
    for (const auto& [col, row] : right_up)
    {
        for (int i = 1; i <= row; ++i)
            for (int j = col + 1; j <= n; ++j)
                area[i][j] = 2;
    }
    for (const auto& [col, row] : left_down)
    {
        for (int i = row; i <= n; ++i)
            for (int j = 1; j < col; ++j)
                area[i][j] = 3;
    }
    for (const auto& [col, row] : right_down)
    {
        for (int i = row + 1; i <= n; ++i)
            for (int j = col; j <= n; ++j)
                area[i][j] = 4;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            area_population[area[i][j]] += population[i][j];
    auto minmax = minmax_element(area_population.begin(), area_population.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    return minmax.second->second - minmax.first->second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    population.resize(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> population[i][j];
            total_population += population[i][j];
        }
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
            for (int d1 = 1; d1 < y; ++d1)
                for (int d2 = 1; d1 + d2 + x <= n && d2 <= n - y; ++d2)
                    res = min(res, population_difference(x, y, d1, d2));
    cout << res;
    return 0;
}