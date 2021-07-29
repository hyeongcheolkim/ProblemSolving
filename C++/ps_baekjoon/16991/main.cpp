//baekjoon ps 16991

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;
using pos = pair<int, int>;

double distance(pos a, pos b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }

int main()
{
    constexpr double INF = numeric_limits<double>::infinity();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pos> graph(n);
    vector<unordered_map<int, double>> dp(n);
    for (int i = 0; i < n; i++)
        cin >> graph[i].first >> graph[i].second;
    function<double(int, int)> dfs = [&](int now, int visited)
    {
        double res = dp[now][visited];
        if (res != 0.0)
            return res;
        if (visited == ((1 << n) - 1))
        {
            if (distance(graph[now], graph[0]) == 0)
                return INF;
            return distance(graph[now], graph[0]);
        }
        res = INF;
        for (int next = 0; next < n; next++)
            if (distance(graph[now], graph[next]) != 0)
                if ((visited & (1 << next)) == 0)
                    res = min(res, distance(graph[now], graph[next]) + dfs(next, visited | 1 << next));
        dp[now][visited] = res;
        return res;
    };
    cout << fixed;
    cout.precision(15);
    cout << dfs(0, 1);
    return 0;
}