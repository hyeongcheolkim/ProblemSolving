#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = numeric_limits<long long>::max() / 2;
int n, m, k, s, p, q;
vector<vector<int>> graph;
vector<bool> is_infected, is_danger;
set<int> infected_city;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
vector<long long> cost;

void decide_danger_city()
{
    for (const auto& infected : infected_city)
    {
        queue<int> q, tq;
        q.emplace(infected);
        vector<bool> vst(n + 1);
        vst[infected] = true;
        for (int i = 0; i < s; ++i)
        {
            while (!q.empty())
            {
                auto now = q.front();
                q.pop();
                for (const auto& next : graph[now])
                {
                    if (vst[next])
                        continue;
                    vst[next] = true;
                    is_danger[next] = true;
                    tq.push(next);
                }
            }
            q.swap(tq);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> s >> p >> q;
    graph.resize(n + 1);
    is_danger.resize(n + 1);
    is_infected.resize(n + 1);
    cost.resize(n + 1, INF);
    while (k--)
    {
        int city;
        cin >> city;
        is_infected[city] = true;
        infected_city.insert(city);
    }
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    decide_danger_city();
    pq.emplace(0, 1);
    cost[1] = 0;
    while (!pq.empty())
    {
        auto [in_cost, now] = pq.top();
        pq.pop();
        if (cost[now] < in_cost)
            continue;
        for (const auto& next : graph[now])
        {
            if (is_infected[next])
                continue;
            const int& out_cost = is_danger[next] ? q : p;
            if (long long new_cost = in_cost + out_cost; new_cost < cost[next])
            {
                cost[next] = new_cost;
                pq.emplace(new_cost, next);
            }
        }
    }
    cout << cost[n] - (is_danger[n] ? q : p);
    return 0;
}