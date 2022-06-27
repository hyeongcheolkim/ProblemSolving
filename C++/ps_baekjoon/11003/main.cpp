#include <bits/stdc++.h>
using namespace std;

int n, l;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        pq.emplace(num, i);
        while (pq.top().second < i - l + 1)
            pq.pop();
        cout << pq.top().first <<' ';
    }
    return 0;
}