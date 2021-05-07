//baekjoon ps 1707

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    while (k--)
    {
        static int v, e;
        static bool flag;
        flag = true;
        cin >> v >> e;
        vector<vector<int>> map(v + 1);
        vector<bool> check(v + 1, 0);
        vector<bool> color(v + 1, 0);
        queue<int> q;
        for (int i = 0; i < e; i++)
        {
            static int to, go;
            cin >> to >> go;
            map[to].push_back(go);
            map[go].push_back(to);
        }
        for (int x = 1; x <= v; x++)
        {
            if (check[x])
                continue;
            if (!flag)
                break;
            check[x] = true;
            color[x] = 0;
            q.push(x);
            while(!q.empty())
            {
                for (int i = 0; i < map[q.front()].size(); i++)
                {
                    if (!check[map[q.front()][i]])
                    {
                        q.push(map[q.front()][i]);
                        check[map[q.front()][i]] = true;
                        color[map[q.front()][i]] = !color[q.front()];
                    }
                    else
                    {
                        if (color[map[q.front()][i]] == color[q.front()])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (!flag)
                    break;
                q.pop();
            }
        }

        if (flag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}