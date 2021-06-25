//baekjoon ps 15686

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

int n, m;
int res = numeric_limits<int>::max();
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int dis(pair<int, int> pos1, pair<int, int> pos2)
{
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

void dfs(int cnt, int index)
{
    static vector<pair<int, int>> temp;
    static vector<bool> check(chicken.size(), false);
    if (cnt == m)
    {
        int sum = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int mindis = numeric_limits<int>::max();
            for (int j = 0; j < temp.size(); j++)
                mindis = min(mindis, dis(house[i], temp[j]));
            sum += mindis;
        }
        res = min(res, sum);
        return;
    }
    for (int i = index; i < chicken.size(); i++)
        if (!check[i])
        {
            check[i] = true;
            temp.push_back(chicken[i]);
            dfs(cnt + 1, i);
            check[i] = false;
            temp.pop_back();
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int data;
            cin >> data;
            switch (data)
            {
            case 1:
                house.push_back({i, j});
                break;
            case 2:
                chicken.push_back({i, j});
                break;
            default:
                break;
            }
        }
    dfs(0, 0);
    cout << res;
    return 0;
}