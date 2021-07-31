//baekjoon ps 3665

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum state
{
    case_normal,
    case_impossible,
    case_question,
};

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
        vector<int> degree(n + 1), ranking(n + 1);
        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; i++)
            cin >> ranking[i];
        for (int from = 1; from <= n; from++)
            for (int to = from + 1; to <= n; to++)
            {
                graph[ranking[from]][ranking[to]] = true;
                degree[ranking[to]]++;
            }
        int m;
        cin >> m;
        while (m--)
        {
            int from, to;
            cin >> from >> to;
            if (!graph[from][to])
                swap(from, to);
            graph[from][to] = false;
            graph[to][from] = true;
            degree[to]--;
            degree[from]++;
        }
        queue<int> q;
        state flag = state::case_normal;
        for (int i = 1; i <= n; i++)
            if (degree[i] == 0)
                q.push(i);
        for (int i = 1; i <= n; i++)
        {
            if (q.size() == 0)
            {
                flag = state::case_impossible;
                break;
            }
            if (q.size() >= 2)
            {
                flag = state::case_question;
                break;
            }
            int now_team = q.front();
            q.pop();
            ranking[i] = now_team;
            for (int next_team = 1; next_team <= n; next_team++)
                if (graph[now_team][next_team])
                    if (--degree[next_team] == 0)
                        q.push(next_team);
        }
        switch (flag)
        {
        case state::case_normal:
            for_each(ranking.begin() + 1, ranking.end(), [](const int &e)
                     { cout << e << ' '; });
            cout << '\n';
            break;
        case state::case_impossible:
            cout << "IMPOSSIBLE\n";
            break;
        case state::case_question:
            cout << "?\n";
            break;
        default:
            break;
        }
    }
    return 0;
}