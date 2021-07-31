//baekjoon ps 3665

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum error
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
        error flag = error::case_normal;
        for (int i = 1; i <= n; i++)
            if (degree[i] == 0)
                q.push(i);
        for (int i = 1; i <= n; i++)
        {
            if (q.size() == 0)
            {
                flag = error::case_impossible;
                break;
            }
            if (q.size() >= 2)
            {
                flag = error::case_question;
                break;
            }
            int team = q.front();
            q.pop();
            ranking[i] = team;
            for (int i = 1; i <= n; i++)
                if (graph[team][i])
                    if (--degree[i] == 0)
                        q.push(i);
        }
        switch (flag)
        {
        case error::case_normal:
            for_each(ranking.begin() + 1, ranking.end(), [](const int &e)
                     { cout << e << ' '; });
            cout << '\n';
            break;
        case error::case_impossible:
            cout << "IMPOSSIBLE\n";
            break;
        case error::case_question:
            cout << "?\n";
            break;
        default:
            break;
        }
    }
    return 0;
}