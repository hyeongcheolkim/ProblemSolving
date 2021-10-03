#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5;
int n, m, k, degree[mxN + 1], ea[mxN + 1];
vector<vector<int>> graph;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    graph.resize(n + 1);
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        ++degree[to];
        graph[from].push_back(to);
    }
    while (k--)
    {
        int opt, num;
        cin >> opt >> num;
        switch (opt)
        {
        case 1:
            if (degree[num] == 0)
            {
                if (ea[num]++ == 0)
                    for (const auto& e : graph[num])
                        --degree[e];
            }
            else
            {
                cout << "Lier!";
                exit(0);
            }
            break;
        case 2:
            if (--ea[num] < 0)
            {
                cout << "Lier!";
                exit(0);
            }
            if (ea[num] == 0)
                for (const auto& e : graph[num])
                    ++degree[e];
            break;
        default:
            break;
        }
    }
    cout << "King-God-Emperor";
    return 0;
}