#include <bits/stdc++.h>
using namespace std;

int n;
bool cmp(const int &a, const int &b)
{
    return a > b;
}
priority_queue<int, vector<int>, decltype(*cmp)> pq(cmp);
vector<pair<int, int>> times;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    times.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int from, to;
        cin >> from >> to;
        times.emplace_back(from, to);
    }
    sort(times.begin(), times.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first < b.first;
    });

    for(const auto&[from, to] : times)
    {
        if (pq.empty())
        {
            pq.push(to);
            continue;
        }
        if (pq.top() <= from)
            pq.pop();
        pq.push(to);
    }
    
    cout << pq.size();
    return 0;
}