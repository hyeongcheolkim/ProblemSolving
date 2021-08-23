#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e6;
bool vst[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    vst[s] = true;
    while (!q.empty())
    {
        auto [floor, cnt] = q.front();
        q.pop();
        if (floor == g)
        {
            cout << cnt;
            exit(0);
        }
        if (floor + u <= f && !vst[floor + u])
        {
            q.emplace(floor + u, cnt + 1);
            vst[floor + u] = true;
        }
        if (1 <= floor - d && !vst[floor - d])
        {
            q.emplace(floor - d, cnt + 1);
            vst[floor - d] = true;
        }
    }
    cout << "use the stairs";
    return 0;
}