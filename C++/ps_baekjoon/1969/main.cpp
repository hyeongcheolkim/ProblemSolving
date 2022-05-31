#include <bits/stdc++.h>
using namespace std;

int n, m, dist;
vector<map<char, int>> cnt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    cnt.resize(m);
    for (int i = 0; i < n; ++i)
    {
        string dna;
        cin >> dna;
        for (int idx = 0; idx < m; ++idx)
            ++cnt[idx][dna[idx]];
    }
    vector<vector<pair<char, int>>> vec_cnt;
    for (const auto& e : cnt)
        vec_cnt.emplace_back(e.begin(), e.end());
    for (auto& e : vec_cnt)
        sort(e.begin(), e.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for (const auto& e : vec_cnt)
    {
        cout << e.front().first;
        dist += accumulate(e.begin() + 1, e.end(), 0, [](int num, auto& e) {return num + e.second; });
    }
    cout << '\n' << dist;
    return 0;
}