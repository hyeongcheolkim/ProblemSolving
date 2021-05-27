//baekjoon ps 1202

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    unsigned long long res = 0;
    cin >> n >> k;
    vector<pair<int, int>> jewel(n);
    vector<int> bag(k);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        cin >> jewel[i].first >> jewel[i].second;
    for (int i = 0; i < k; i++)
        cin >> bag[i];
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());
    for (int i = 0; i < k; i++)
    {
        for (static int index = 0; index < n && jewel[index].first <= bag[i]; index++)
            pq.push(jewel[index].second);
        if (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res;
    return 0;
}