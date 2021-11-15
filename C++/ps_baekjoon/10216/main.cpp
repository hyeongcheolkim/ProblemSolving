#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;
using circle = pair<pos, int>;

int n, cnt;
vector<circle> arr;
vector<bool> vst;

double distance(pos a, pos b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }

void dfs(int idx)
{
    auto [Pa, Ra] = arr[idx];
    for (int i = 0; i < n; ++i)
        if (!vst[i])
        {
            auto [Pb, Rb] = arr[i];
            if (distance(Pa, Pb) <= Ra + Rb)
            {
                vst[i] = true;
                dfs(i);
            }
        }
}

void init()
{
    cnt = 0;
    arr.resize(0);
    arr.reserve(n);
    vst.assign(n, false);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        init();
        for (int i = 0; i < n; ++i)
        {
            int x, y, r;
            cin >> x >> y >> r;
            arr.emplace_back(pos{x, y}, r);
        }
        for (int i = 0; i < n; ++i)
            if (!vst[i])
            {
                vst[i] = true;
                ++cnt;
                dfs(i);
            }
        cout << cnt << '\n';
    }
    return 0;
}