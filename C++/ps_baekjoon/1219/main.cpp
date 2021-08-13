//baekjoon ps 1219

#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    constexpr long long INF = numeric_limits<long long>::max() / 2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, start, end, m;
    cin >> n >> start >> end >> m;
    vector<vector<pair<int, int>>> map(n);
    vector<long long> money(n, -INF);
    vector<int> income(n);
    queue<int> q;
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        map[from].emplace_back(to, cost);
    }
    for (int i = 0; i < n; ++i)
        cin >> income[i];
    money[start] = income[start];
    for (int cnt = 0; cnt < n; ++cnt)
    {
        bool update = false;
        for (int now = 0; now < n; ++now)
            for (const auto &e : map[now])
            {
                auto [next, cost] = e;
                if (money[now] == -INF)
                    continue;
                if (money[next] < money[now] + income[next] - cost)
                {
                    money[next] = money[now] + income[next] - cost;
                    update = true;
                    if (cnt == n - 1)
                        q.emplace(now);
                }
            }
        if (!update)
            break;
    }
    bool flag = false;
    vector<int> visited(n);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (visited[now])
            continue;
        visited[now] = true;
        for (const auto &next : map[now])
        {
            if (next.first == end)
            {
                flag = true;
                break;
            }
            if (!visited[next.first])
                q.emplace(next.first);
        }
        if(flag)
            break;
    }
    if (money[end] == -INF)
        cout << "gg";
    else if (flag)
        cout << "Gee";
    else
        cout << money[end];
    return 0;
}