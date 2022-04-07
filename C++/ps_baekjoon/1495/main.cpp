#include <bits/stdc++.h>
using namespace std;

int n, s, m, maxi = -1;
vector<int> volume;
vector<vector<bool>> playable;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> m;
    volume.resize(n + 1);
    playable.resize(n + 1, vector<bool>(m + 1));
    for (int i = 1; i <= n; ++i)
        cin >> volume[i];
    playable[0][s] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            if (playable[i - 1][j])
                for (const auto& weight : {+1, -1})
                {
                    int next_volume = j + weight * volume[i];
                    if (next_volume < 0 || next_volume >m)
                        continue;
                    playable[i][next_volume] = true;
                }
    for (int i = m; i >= 0; --i)
        if (playable[n][i])
        {
            cout << i;
            exit(0);
        }
    cout << -1;
    return 0;
}