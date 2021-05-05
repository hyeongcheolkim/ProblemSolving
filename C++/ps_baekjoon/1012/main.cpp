//baekjoon ps 1012

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
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int m, n, k;
        int res = 0;
        cin >> m >> n >> k;
        vector<vector<bool>> map(n + 2, vector<bool>(m + 2, false));
        vector<vector<bool>> check(n + 2, vector<bool>(m + 2, false));

        while (k--)
        {
            int col, row;
            cin >> col >> row;
            map[row + 1][col + 1] = true;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!check[i][j])
                    switch ((int)map[i][j])
                    {
                    case 0:
                        check[i][j] = true;
                        break;
                    case 1:
                    {
                        res++;
                        queue<pair<int, int>> q;
                        int cnt = 0;
                        q.push({i, j});
                        check[i][j] = true;
                        while (!q.empty())
                        {
                            for (int dx = 0; dx < 4; dx++)
                            {
                                if (!check[q.front().first + drow[dx]][q.front().second + dcol[dx]] && map[q.front().first + drow[dx]][q.front().second + dcol[dx]] == 1)
                                    q.push({q.front().first + drow[dx], q.front().second + dcol[dx]});
                                check[q.front().first + drow[dx]][q.front().second + dcol[dx]] = true;
                            }
                            if (map[q.front().first][q.front().second] == 1)
                                cnt++;
                            q.pop();
                        }
                        break;
                    }
                    default:
                        break;
                    }
        cout << res << '\n';
    }
    return 0;
}