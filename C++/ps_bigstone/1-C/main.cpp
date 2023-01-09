#include <bits/stdc++.h>
using namespace std;

constexpr int mxT = 100;
int total_fee;
unordered_map<int, int> cnt, fee;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 3; ++i)
        cin >> fee[i];
    for (int i = 0; i < 3; ++i)
    {
        int u, v;
        cin >> u >> v;
        for (int i = u; i < v; ++i)
            ++cnt[i];
    }
    for (int i = 1; i <= mxT; ++i)
        total_fee += fee[cnt[i]] * cnt[i];
    cout << total_fee;
    return 0;
}