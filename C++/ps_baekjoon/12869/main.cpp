#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 3, mxHP = 60, INF = numeric_limits<int>::max() / 2;
int n, hp[mxN + 1], dp[mxHP + 1][mxHP + 1][mxHP + 1];

int solve(int hp1, int hp2, int hp3)
{
    for (const auto& e : {&hp1, &hp2, &hp3})
        *e = *e < 0 ? 0 : *e;
    int& ret = dp[hp1][hp2][hp3];
    if (ret != -1)
        return ret;
    if (!(hp1 || hp2 || hp3))
        return ret = 0;
    ret = INF;
    array<int, 3> gradients{-9, -3, -1};
    do
    {
        const int& d1 = gradients[0];
        const int& d2 = gradients[1];
        const int& d3 = gradients[2];
        ret = min(ret, solve(hp1 + d1, hp2 + d2, hp3 + d3) + 1);
    } while (next_permutation(gradients.begin(), gradients.end()));
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> hp[i];
    cout << solve(hp[1], hp[2], hp[3]);
    return 0;
}