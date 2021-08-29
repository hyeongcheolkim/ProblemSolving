#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, cnt = 0;
    cin >> n;
    vector<int> crane(n);
    for (int i = 0; i < n; ++i)
        cin >> crane[i];
    cin >> m;
    vector<int> luggage(m);
    for (int i = 0; i < m; ++i)
        cin >> luggage[i];
    sort(crane.begin(), crane.end(), greater<int>());
    sort(luggage.begin(), luggage.end(), greater<int>());
    if (crane.front() < luggage.front())
    {
        cout << -1;
        return 0;
    }
    auto iter_c = crane.begin();
    auto iter_l = luggage.begin();
    while (!luggage.empty())
        if (*iter_c >= *iter_l)
        {
            luggage.erase(iter_l);
            ++iter_c;
            if (iter_l == luggage.end() || iter_c == crane.end())
            {
                ++cnt;
                iter_c = crane.begin();
                iter_l = luggage.begin();
                continue;
            }
        }
        else
        {
            ++iter_l;
            if (iter_l == luggage.end())
            {
                ++cnt;
                iter_c = crane.begin();
                iter_l = luggage.begin();
                continue;
            }
        }
    cout << cnt;
    return 0;
}