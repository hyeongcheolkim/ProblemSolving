#include <bits/stdc++.h>
using namespace std;

int n, begin_day, end_day, cnt;
map<int, int> month_last_day;
vector<pair<int, int>> flowers;

int to_days(int mm, int dd)
{
    int ret = 0;
    for (int i = 1; i < mm; ++i)
        ret += month_last_day[i];
    ret += dd;
    return ret;
}

void init()
{
    for (const auto& e : vector<int>{1, 3, 5, 7, 8, 10, 12})
        month_last_day[e] = 31;
    for (const auto& e : vector<int>{4, 6, 9, 11})
        month_last_day[e] = 30;
    month_last_day[2] = 28;
    begin_day = to_days(3, 1);
    end_day = to_days(12, 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    init();
    cin >> n;
    while (n--)
    {
        int begin_mm, begin_dd, end_mm, end_dd;
        cin >> begin_mm >> begin_dd >> end_mm >> end_dd;
        int begin_day = to_days(begin_mm, begin_dd);
        int end_day = to_days(end_mm, end_dd);
        flowers.emplace_back(begin_day, end_day);
    }
    sort(flowers.begin(), flowers.end());
    int idx = 0;
    int target_day = begin_day;
    while (idx < flowers.size() && target_day < end_day)
    {
        int max_end_day = 0;
        while (idx < flowers.size() && flowers[idx].first <= target_day)
        {
            max_end_day = max(max_end_day, flowers[idx].second);
            ++idx;
        }
        if (max_end_day == 0)
            break;
        target_day = max_end_day;
        ++cnt;
    }
    if (target_day < end_day)
        cout << 0;
    else
        cout << cnt;
    return 0;
}