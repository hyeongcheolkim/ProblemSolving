//baekjoon ps 10026

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int dr[4] = {0, 0, +1, -1};
    constexpr int dc[4] = {+1, -1, 0, 0};
    int n, res1 = 0, res2 = 0;
    cin >> n;
    vector<vector<bool>> check1(n + 2, vector<bool>(n + 2, false));
    vector<vector<bool>> check2(n + 2, vector<bool>(n + 2, false));
    queue<tuple<char, char, char>> q1;
    queue<tuple<char, char, char>> q2;
    vector<vector<char>> map1(n + 2, vector<char>(n + 2, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map1[i][j];
    vector<vector<char>> map2(map1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            map2[i][j] = (map2[i][j] == 'G' ? 'R' : map2[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!check1[i][j])
            {
                q1.push({map1[i][j], i, j});
                check1[i][j] = true;
                res1++;
            }
            if (!check2[i][j])
            {
                q2.push({map2[i][j], i, j});
                check2[i][j] = true;
                res2++;
            }
            while (!q1.empty())
            {
                char color = get<0>(q1.front());
                char row = get<1>(q1.front());
                char col = get<2>(q1.front());
                q1.pop();
                for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
                    if (!check1[row + dr[i]][col + dc[i]] && map1[row + dr[i]][col + dc[i]] == color)
                    {
                        q1.push({color, row + dr[i], col + dc[i]});
                        check1[row + dr[i]][col + dc[i]] = true;
                    }
            }
            while (!q2.empty())
            {
                char color = get<0>(q2.front());
                char row = get<1>(q2.front());
                char col = get<2>(q2.front());
                q2.pop();
                for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
                    if (!check2[row + dr[i]][col + dc[i]] && (map2[row + dr[i]][col + dc[i]]) == color)
                    {
                        q2.push({color, row + dr[i], col + dc[i]});
                        check2[row + dr[i]][col + dc[i]] = true;
                    }
            }
        }
    cout << res1 << " " << res2;
    return 0;
}