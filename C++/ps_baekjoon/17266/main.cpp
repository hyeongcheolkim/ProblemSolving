#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> pos;

bool condition(int val)
{
    for (int i = 0; i < pos.size(); ++i)
    {
        const int &p = pos[i];
        if (i == 0 && p - val > 0)
            return false;

        if (i == pos.size() - 1 && p + val < n)
            return false;

        if (i != 0 && p - 2 * val > pos[i - 1])
            return false;

        if(i != pos.size() - 1 && p + 2 * val < pos[i + 1])
            return false;
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    pos.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> pos[i];

    int lt = 0;
    int rt = n + 1;
    while (lt + 1 < rt)
    {
        int mid = (rt - lt) / 2 + lt;

        if (condition(mid))
        {
            rt = mid;
        }
        else
        {
            lt = mid;
        }
    }
    cout << rt;
    return 0;
}