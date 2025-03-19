#include <bits/stdc++.h>
using namespace std;

int n, d, answer;
vector<pair<int, int>> arr;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int h, o;
        cin >> h >> o;
        arr.emplace_back(min(h, o), max(h, o));
    }
    cin >> d;
    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second; });

    for (const auto &[h, o] : arr)
    {
        int len = o - h;
        if (len > d)
            continue;
        if (pq.empty())
        {
            pq.emplace(h, o);
            answer = max(answer, static_cast<int>(pq.size()));
            continue;
        }

        while (!pq.empty())
        {
            int lt = pq.top().first;
            if (lt >= o - d)
                break;
            pq.pop();
        }
        pq.emplace(h, o);
        answer = max(answer, static_cast<int>(pq.size()));
        continue;
    }
    cout << answer;
    return 0;
}