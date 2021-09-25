#include <bits/stdc++.h>
using namespace std;

int n, total;
vector<pair<int, int>> arr;
priority_queue<int> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    for (int i = arr.back().first; i > 0; --i)
    {
        while (!arr.empty() && arr.back().first == i)
        {
            pq.push(arr.back().second);
            arr.pop_back();
        }
        if (!pq.empty())
        {
            total += pq.top();
            pq.pop();
        }
    }
    cout << total;
    return 0;
}