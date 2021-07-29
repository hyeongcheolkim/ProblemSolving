//baekjoon ps 2618

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;
using pos = pair<int, int>;

int distance(pos a, pos b) { return abs(a.first - b.first) + abs(a.second - b.second); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, w;
    cin >> n >> w;
    deque<pos> car_a(w), car_b;
    vector<vector<int>> dp(w + 1, vector<int>(w + 1, -1));
    vector<int> trace;
    trace.reserve(w);
    for (int i = 0; i < w; i++)
        cin >> car_a[i].first >> car_a[i].second;
    car_b = car_a;
    car_a.push_front({1, 1});
    car_b.push_front({n, n});
    function<int(int, int)> recursion = [&](int a, int b)
    {
        if (a == w || b == w)
            return 0;
        int &now = dp[a][b];
        if (now != -1)
            return now;
        int next_incident = max(a, b) + 1;
        int dist_a = recursion(next_incident, b) + distance(car_a[a], car_a[next_incident]);
        int dist_b = recursion(a, next_incident) + distance(car_b[b], car_b[next_incident]);
        return now = min(dist_a, dist_b);
    };
    function<void(int, int)> tracing = [&](int a, int b)
    {
        if (a == w || b == w)
            return;
        int next_incident = max(a, b) + 1;
        int dist_a = recursion(next_incident, b) + distance(car_a[a], car_a[next_incident]);
        int dist_b = recursion(a, next_incident) + distance(car_b[b], car_b[next_incident]);
        if (dist_a > dist_b)
        {
            trace.push_back(2);
            tracing(a, next_incident);
        }
        else
        {
            trace.push_back(1);
            tracing(next_incident, b);
        }
    };
    cout << recursion(0, 0) << '\n';
    tracing(0, 0);
    for (int i = 0; i < trace.size(); i++)
        cout << trace[i] << '\n';
    return 0;
}