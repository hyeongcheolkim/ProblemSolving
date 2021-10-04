#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 14, dr[]{0,0,+1,-1}, dc[]{+1,-1,0,0};
int n;
double possibility[4], res;
bool vst[mxN * 2 + 1][mxN * 2 + 1];

void dfs(int r = mxN, int c = mxN, int level = 0, double event = 1.0)
{
    if (level == n)
    {
        res += event;
        return;
    }
    for (int direction = 0; direction < 4; ++direction)
    {
        int nr = r + dr[direction];
        int nc = c + dc[direction];
        if (vst[nr][nc])
            continue;
        vst[nr][nc] = true;
        dfs(nr, nc, level + 1, event * possibility[direction]);
        vst[nr][nc] = false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < 4; ++i)
    {
        cin >> possibility[i];
        possibility[i] /= 100.0;
    }
    vst[mxN][mxN] = true;
    dfs();
    cout << fixed << setprecision(10) << res;
    return 0;
}