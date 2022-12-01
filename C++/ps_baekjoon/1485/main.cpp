#include <bits/stdc++.h>
using namespace std;
using pos = pair<long long, long long>;
int t;

long long distance(pos p1, pos p2)
{
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        vector<pos> pos_vec(4);
        for (int i = 0; i < 4; ++i)
            cin >> pos_vec[i].first >> pos_vec[i].second;
        set<long long> dist;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
            {
                if (i == j)
                    continue;
                dist.insert(distance(pos_vec[i], pos_vec[j]));
            }
        cout << (dist.size() == 2) << '\n';
    }
    return 0;
}