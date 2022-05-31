#include <bits/stdc++.h>
using namespace std;

int n, mini = numeric_limits<int>::max();
vector<vector<int>> graph;

int ability(const vector<int>& team)
{
    int ret = 0;
    for (int i = 0; i < team.size(); ++i)
        for (int j = i + 1; j < team.size(); ++j)
            ret += graph[team[i]][team[j]] + graph[team[j]][team[i]];
    return ret;
}

void dfs(int level = 0)
{
    static vector<int> team1, team2;
    if (level == n)
    {
        if (team1.empty() || team2.empty())
            return;
        auto ability1 = ability(team1);
        auto ability2 = ability(team2);
        mini = min(mini, abs(ability1 - ability2));
        return;
    }
    team1.push_back(level + 1);
    dfs(level + 1);
    team1.pop_back();
    team2.push_back(level + 1);
    dfs(level + 1);
    team2.pop_back();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    graph.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> graph[i][j];
    dfs();
    cout << mini;
    return 0;
}