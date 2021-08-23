#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e3;
bool vst[2 * mxN + 1][2 * mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int s;
    cin >> s;
    vst[1][0] = true;
    queue<tuple<int, int, int>> q;
    q.emplace(1, 0, 0);
    while (!q.empty())
    {
        auto [screen, clipboard, time] = q.front();
        q.pop();
        if (screen == s)
        {
            cout << time;
            break;
        }
        if (!vst[screen][screen])
        {
            vst[screen][screen] = true;
            q.emplace(screen, screen, time + 1);
        }
        if (clipboard && screen + clipboard <= mxN && !vst[screen + clipboard][clipboard])
        {
            vst[screen + clipboard][clipboard] = true;
            q.emplace(screen + clipboard, clipboard, time + 1);
        }
        if (!vst[screen - 1][clipboard] && screen - 1 != 0)
        {
            vst[screen - 1][clipboard] = true;
            q.emplace(screen - 1, clipboard, time + 1);
        }
    }
    return 0;
}