//baekjoon ps 11657

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr long long INF = 2000000000000;
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> map(n + 1);
    vector<long long> time(n + 1, INF);
    vector<bool> check(n + 1);
    time[1] = 0;
    for (int i = 0; i < m; i++)
    {
        static int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b, c});
    }
    for (int x = 1; x < n; x++)
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < map[i].size(); j++)
                if (time[i] != INF)
                    time[map[i][j].first] = min(time[map[i][j].first], time[i] + map[i][j].second);

    vector<long long> test(time);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < map[i].size(); j++)
            if (time[i] != INF)
                test[map[i][j].first] = min(test[map[i][j].first], test[i] + map[i][j].second);

    if (test == time)
        for (int i = 2; i <= n; i++)
            cout << (time[i] != INF ? time[i] : -1) << '\n';
    else
        cout << -1;

    return 0;
}