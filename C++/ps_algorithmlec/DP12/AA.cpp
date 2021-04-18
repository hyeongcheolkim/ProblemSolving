// cpp algorithm ps number DP12

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 217400000));
    for (int i = 1; i <= n; i++)
        map[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        static int to, go, cost;
        cin >> to >> go >> cost;
        map[to][go] = cost;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= 5; k++)
                map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if(map[i][j]==217400000)
                cout << 'M';
            else cout << map[i][j];
        cout << '\n';
    }
    return 0;
}