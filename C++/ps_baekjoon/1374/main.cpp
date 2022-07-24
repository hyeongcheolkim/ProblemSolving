#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> time_table;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int num, start, end;
        cin >> num >> start >> end;
        time_table.emplace_back(start, end);
    }
    sort(time_table.begin(), time_table.end());
    pq.push(time_table.front().second);
    for (int i = 1; i < time_table.size(); ++i)
    {
        const auto& [start, end] = time_table[i];
        if (start >= pq.top())
            pq.pop();
        pq.push(end);
    }
    cout << pq.size();
    return 0;
}