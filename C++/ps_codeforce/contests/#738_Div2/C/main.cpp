//ps C

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int vertex = n + 1;
        vector<vector<int>> graph(vertex + 1);
        for (int i = 1; i < vertex - 1; ++i)
            graph[i].push_back(i + 1);
        for (int i = 1; i < vertex; i++)
        {
            int num;
            cin >> num;
            if (num)
                graph[vertex].push_back(i);
            else
                graph[i].push_back(vertex);
        }
        vector<bool> visit(vertex + 1, false);
        vector<int> trace;
        trace.reserve(vertex);
        bool flag = false;
        function<void(int, int)> dfs = [&](int now, int cnt)
        {
            if (cnt == vertex)
            {
                for (const auto &e : trace)
                    cout << e << ' ';
                cout << '\n';
                flag = true;
                return;
            }
            if (flag)
                return;
            for (int i = 0; i < graph[now].size(); ++i)
            {
                int next = graph[now][i];
                if (visit[next])
                    continue;
                if (flag)
                    break;
                visit[next] = true;
                trace.push_back(next);
                dfs(next, cnt + 1);
                trace.pop_back();
                visit[next] = false;
            }
        };
        for (int i = 1; i <= vertex; ++i)
        {
            visit[i] = true;
            trace.push_back(i);
            dfs(i, 1);
            if (flag)
                break;
            trace.pop_back();
            visit[i] = false;
        }
    }
    return 0;
}