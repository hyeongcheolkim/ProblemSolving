#include <bits/stdc++.h>
using namespace std;

struct lecture
{
    int day, pay;
    lecture() {}
    bool operator<(const lecture& obj) const { return this->pay < obj.pay; }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, max_day = 0, res = 0;
    cin >> n;
    vector<lecture> lectures(n);
    priority_queue<lecture> pq;
    for (int i = 0; i < n; ++i)
    {
        cin >> lectures[i].pay >> lectures[i].day;
        max_day = max(max_day, lectures[i].day);
    }
    sort(lectures.begin(), lectures.end(), [](lecture a, lecture b) { return a.day < b.day; });
    for (int today = max_day; today > 0; --today)
    {
        while (!lectures.empty() && lectures.back().day == today)
        {
            pq.push(lectures.back());
            lectures.pop_back();
        }
        if (!pq.empty())
        {
            res += pq.top().pay;
            pq.pop();
        }
    }
    cout << res;
    return 0;
}