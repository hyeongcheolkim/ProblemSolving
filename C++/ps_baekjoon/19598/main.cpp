#include <bits/stdc++.h>
using namespace std;

int n;
bool cmp(const int &a, const int &b) { return a > b; }
priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);
vector<pair<int, int>> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; });

    for (const auto &[start, end] : arr)
    {
        if (pq.empty())
        {
            pq.push(end);
            continue;
        }
        if (pq.top() <= start)
            pq.pop();
        pq.push(end);
    }
    cout << pq.size();
    return 0;
}