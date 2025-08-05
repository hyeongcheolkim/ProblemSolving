#include <bits/stdc++.h>
using namespace std;

int n, m, answer;
vector<vector<int>> graph1, graph2;

int count_ball(int node, vector<vector<int>>& graph)
{
    int ret = 0;

    queue<int> q;
    q.push(node);
    vector<bool> vst(n + 1);
    vst[node] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(const int& next : graph[now])
        {
            if(vst[next])
                continue;

            vst[next] = true;
            q.push(next);
            ++ret;
        }
    }

    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph1.resize(n + 1);
    graph2.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int w1, w2;
        cin >> w1 >> w2;
        graph1[w1].push_back(w2);
        graph2[w2].push_back(w1);

    }

    int mid = (n + 1) / 2;
    for (int i = 1; i <= n; ++i)
    {
        int cnt1 = count_ball(i, graph1);
        int cnt2 = count_ball(i, graph2);

        if(cnt1 >= mid || cnt2 >= mid)
            ++answer;
    }
    cout << answer;
    return 0;
}