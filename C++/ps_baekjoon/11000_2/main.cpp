#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.reserve(n);
    while (n--)
    {
        int s, t;
        cin >> s >> t;
        arr.emplace_back(s, t);
    }
    sort(arr.begin(), arr.end());
    pq.emplace(arr.front().second);
    for (int i = 1; i < arr.size(); ++i)
    {
        const auto& [s, t] = arr[i];
        if (pq.top() <= s)
            pq.pop();
        pq.emplace(t);
    }
    cout << pq.size();
    return 0;
}