#include <bits/stdc++.h>
using namespace std;

int n, w, l;
queue<int> truck;
deque<pair<int, int>> bridge;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> w >> l;
    for (int i = 0; i < n; ++i)
    {
        int weight;
        cin >> weight;
        truck.push(weight);
    }
    int time = 0;
    while (!truck.empty() || !bridge.empty())
    {
        static int total_weight = 0;
        for_each(bridge.begin(), bridge.end(), [](auto& e) {--e.first; });
        if (!bridge.empty() && bridge.front().first == 0)
        {
            total_weight -= bridge.front().second;
            bridge.pop_front();
        }
        if (!truck.empty() && total_weight + truck.front() <= l)
        {
            total_weight += truck.front();
            bridge.emplace_back(w, truck.front());
            truck.pop();
        }
        ++time;
    }
    cout << time;
    return 0;
}