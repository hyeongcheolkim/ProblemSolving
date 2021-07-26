//baekjoon ps 2623

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> degree(n + 1);
    vector<int> res;
    queue<int> q;
    res.reserve(n);
    while (m--)
    {
        int num;
        cin >> num;
        vector<int> arr(num);
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        for (int i = 0; i < arr.size() - 1; i++)
            for (int j = i + 1; j < arr.size(); j++)
            {
                graph[arr[i]].push_back(arr[j]);
                degree[arr[j]]++;
            }
    }
    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int now = q.front();
        res.push_back(now);
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            degree[next]--;
            if (degree[next] == 0)
                q.push(next);
        }
    }
    if (res.size() == n)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << '\n';
    }
    else
        cout << 0;
    return 0;
}