//baekjoon ps 11000

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> subject(n);
    for (int i = 0; i < n; ++i)
        cin >> subject[i].first >> subject[i].second;
    sort(subject.begin(), subject.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(subject[0].second, subject[0].first);
    for (int i = 1; i < subject.size(); ++i)
    {
        if (pq.top().first > subject[i].first)
            pq.emplace(subject[i].second, subject[i].first);
        else
        {
            pq.pop();
            pq.emplace(subject[i].second, subject[i].first);
        }
    }
    cout << pq.size();
    return 0;
}