//baekjoon ps 18111

#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

pair<int, int> calculate(const int &floor, const long long &b, const vector<vector<int>> &map)
{
    int time = 0;
    long long cnt = b;
    for (int i = 0; i < map.size(); i++)
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] > floor)
            {
                time += (map[i][j] - floor) * 2;
                cnt += map[i][j] - floor;
            }
            else if (map[i][j] < floor)
            {
                time += (floor - map[i][j]);
                cnt -= floor - map[i][j];
            }
        }
    return {time, cnt};
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    long long b;
    int mini = INT_MAX;
    int maxi = -1;
    pair<int, int> res = {INT_MAX, 0};
    cin >> n >> m >> b;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    for (int i = 0; i <= 256; i++)
    {
        auto out = calculate(i, b, map);
        if (out.second >= 0)
            if (res.first >= out.first)
            {
                res.first = out.first;
                res.second = i;
            }
    }
    cout << res.first << " " << res.second;
    return 0;
}