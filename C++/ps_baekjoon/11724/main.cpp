//baekjoon ps 11724

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    vector<vector<int>> map(n + 1);
    vector<bool> check(n + 1, false);
    queue<int> q;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            q.push(i);
            cnt++;
            check[i] = true;
        }
        while (!q.empty())
        {
            int fn = q.front();
            q.pop();
            for (const auto e : map[fn])
                if (!check[e])
                {
                    q.push(e);
                    check[e] = true;
                }
        }
    }
    cout << cnt;
    return 0;
}