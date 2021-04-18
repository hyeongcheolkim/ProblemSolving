// cpp algorithm ps number DP13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int mini = INT_MAX;
    int cnt = 0;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 2700000));
    vector<int> num;
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    while (true)
    {
        static int to, go;
        cin >> to >> go;
        if (to == -1 && go == -1)
            break;
        graph[to][go] = 1;
        graph[go][to] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    for (int i = 1; i <= n; i++)
    {
        static int temp;
        temp = -1;
        for (int j = 1; j <= n; j++)
            if (graph[i][j] < 274000)
                if (temp < graph[i][j])
                    temp = graph[i][j];

        if (mini > temp)
        {
            mini = temp;
            cnt = 1;
            num.clear();
            num.push_back(i);
        }
        else if (mini == temp)
        {
            cnt++;
            num.push_back(i);
        }
    }
    cout << mini << ' ' << cnt << '\n';
    for (const auto &e : num)
        cout << e << ' ';
    return 0;
}