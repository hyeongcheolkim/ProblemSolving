//baekjoon ps 1167

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int v;
vector<pair<int, int>> *map;
bool *check;
int maxi = -1;
int vertex = -1;
void bfs(int v, int sum)
{
    if (map[v].size() == 1 && check[map[v][0].first])
    {
        if (maxi < sum)
        {
            maxi = sum;
            vertex = v;
        }
        return;
    }
    check[v] = true;
    for (int i = 0; i < map[v].size(); i++)
        if (!check[map[v][i].first])
            bfs(map[v][i].first, sum + map[v][i].second);
    check[v] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> v;
    map = new vector<pair<int, int>>[v + 1];
    check = new bool[v + 1]{false};
    for (int i = 0; i < v; i++)
    {
        static int to, go, cost;
        cin >> to;
        while (true)
        {
            cin >> go;
            if (go == -1)
                break;
            cin >> cost;
            map[to].push_back({go, cost});
        }
    }
    bfs(1, 0);
    bfs(vertex, 0);
    cout << maxi;
    delete[] map;
    delete[] check;
    return 0;
}