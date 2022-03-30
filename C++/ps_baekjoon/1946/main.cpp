#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0, mini = INF;
        cin >> n;
        vector<pair<int, int>> score(n);
        for (auto& [s1, s2] : score)
            cin >> s1 >> s2;
        sort(score.begin(), score.end());
        for (const auto& [s1, s2] : score)
            if (s2 < mini)
            {
                mini = s2;
                ++cnt;
            }
        cout << cnt << '\n';
    }
    return 0;
}