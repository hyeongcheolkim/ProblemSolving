//baekjoon ps 10282

#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

struct Com
{
    int com;
    int cost;
    Com(const int &com, const int &cost)
    {
        this->com = com;
        this->cost = cost;
    }
    bool operator<(const Com &obj) const
    {
        return this->cost > obj.cost;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    constexpr int INF = numeric_limits<int>::max();
    int t;
    cin >> t;
    while (t--)
    {
        int time = -1;
        int num = 0;
        int n, d, c;
        cin >> n >> d >> c;
        vector<vector<Com>> map(n + 1);
        vector<int> dist(n + 1, INF);
        priority_queue<Com> pq;
        while (d--)
        {
            int a, b, s;
            cin >> a >> b >> s;
            map[b].push_back(Com(a, s));
        }
        dist[c] = 0;
        pq.push(Com(c, 0));
        while (!pq.empty())
        {
            auto nowcost = pq.top().cost;
            auto nowcom = pq.top().com;
            pq.pop();
            if (nowcost > dist[nowcom])
                continue;
            for (int i = 0; i < map[nowcom].size(); i++)
            {
                auto nextcost = nowcost + map[nowcom][i].cost;
                auto nextcom = map[nowcom][i].com;
                if (dist[nextcom] > nextcost)
                {
                    dist[nextcom] = nextcost;
                    pq.push(Com(nextcom, nextcost));
                }
            }
        }
        for (int i = 1; i < dist.size(); i++)
            if (dist[i] != INF)
            {
                time = max(time, dist[i]);
                num++;
            }
        cout << num << ' ' << time << '\n';
    }
    return 0;
}