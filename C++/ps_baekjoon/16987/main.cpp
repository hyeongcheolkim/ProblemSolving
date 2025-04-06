#include <bits/stdc++.h>
using namespace std;

int n, answer = 0;
vector<int> weight, durability;

void dfs(int level = 0)
{
    if (level == n)
    {
        int cnt = static_cast<int>(count_if(durability.begin(), durability.end(), [](const int &e)
                                            { return e <= 0; }));
        answer = max(answer, cnt);
        return;
    }
    if (durability[level] <= 0)
    {
        dfs(level + 1);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i == level)
            continue;
        if (durability[i] <= 0)
        {
            dfs(level + 1);
        }
        else
        {
            durability[level] -= weight[i];
            durability[i] -= weight[level];
            dfs(level + 1);
            durability[i] += weight[level];
            durability[level] += weight[i];
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    weight = durability = vector<int>(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int s, w;
        cin >> durability[i] >> weight[i];
    }
    dfs();
    cout << answer;
    return 0;
}