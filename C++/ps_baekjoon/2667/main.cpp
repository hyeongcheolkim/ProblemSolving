//baekjoon ps 2667

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int drow[] = {-1, +1, 0, 0};
int dcol[] = {0, 0, -1, +1};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int town = 0;
    cin >> n;
    vector<vector<char>> map(n + 2, vector<char>(n + 2, 0));
    vector<vector<bool>> check(n + 2, vector<bool>(n + 2, false));
    vector<int> res;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            map[i][j] -= '0';
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!check[i][j])
                switch (map[i][j])
                {
                case 0:
                    check[i][j] = true;
                    break;
                case 1:
                {
                    town++;
                    queue<pair<int, int>> q;
                    int cnt = 0;
                    q.push({i, j});
                    check[i][j] = true;
                    while (!q.empty())
                    {
                        for (int dx = 0; dx < 4; dx++)
                        {
                            if (!check[q.front().first + drow[dx]][q.front().second + dcol[dx]] && map[q.front().first + drow[dx]][q.front().second + dcol[dx]]==1)
                                q.push({q.front().first + drow[dx], q.front().second + dcol[dx]});
                            check[q.front().first + drow[dx]][q.front().second + dcol[dx]] = true;
                        }
                        if (map[q.front().first][q.front().second] == 1)
                            cnt++;
                        q.pop();
                    }
                    res.push_back(cnt);
                    break;
                }
                default:
                    break;
                }
    sort(res.begin(), res.end());
    cout << town << '\n';
    for(const auto &e:res)
        cout << e << '\n';
    return 0;
}