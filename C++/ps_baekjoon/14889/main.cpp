//baekjoon ps 14889

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int team[25];
int check[25];
int mini = INT_MAX;
void bfs(int level, int index, const vector<vector<int>> &stat)
{
    if (level == n / 2)
    {
        static int t1, t2;
        t1 = t2 = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                if (check[i] && check[j])
                    t1 += stat[i][j] + stat[j][i];
                if (!check[i] && !check[j])
                    t2 += stat[i][j] + stat[j][i];
            }
        mini = min(mini, abs(t1 - t2));
        return;
    }
    for (int i = index; i < n; i++)
    {
        check[i] = 1;
        bfs(level + 1, i + 1, stat);
        check[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<vector<int>> stat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> stat[i][j];
    bfs(0, 0, stat);
    cout << mini;
    return 0;
}