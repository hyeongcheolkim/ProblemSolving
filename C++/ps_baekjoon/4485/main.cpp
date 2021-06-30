//baekjoon ps 4485

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct pos
{
    int row, col;
    int cost;
    pos(const int &row, const int &col, const int &cost)
    {
        this->row = row;
        this->col = col;
        this->cost = cost;
    }
    bool operator<(const pos &obj) const
    {
        return this->cost > obj.cost;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    constexpr int dr[] = {0, 0, +1, -1};
    constexpr int dc[] = {+1, -1, 0, 0};
    constexpr int INF = numeric_limits<int>::max();
    for (int num = 1;; num++)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<vector<int>> map(n + 2, vector<int>(n + 2, -1));
        vector<vector<int>> dist(n + 2, vector<int>(n + 2, INF));
        priority_queue<pos> pq;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> map[i][j];
        pq.push(pos(1, 1, map[1][1]));
        dist[1][1] = map[1][1];
        while (!pq.empty())
        {
            int nowrow = pq.top().row;
            int nowcol = pq.top().col;
            int nowcost = pq.top().cost;
            pq.pop();
            if (nowcost > dist[nowrow][nowcol])
                continue;
            for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
            {
                int nextrow = nowrow + dr[i];
                int nextcol = nowcol + dc[i];
                if (map[nextrow][nextcol] == -1)
                    continue;
                int nextcost = nowcost + map[nextrow][nextcol];
                if (dist[nextrow][nextcol] > nextcost)
                {
                    dist[nextrow][nextcol] = nextcost;
                    pq.push(pos(nextrow, nextcol, nextcost));
                }
            }
        }
        cout << "Problem " << num << ": " << dist[n][n] << '\n';
    }
    return 0;
}