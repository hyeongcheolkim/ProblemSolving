#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    map<int, int> cnt;
    for (int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        ++cnt[num];
    }
    vector<pair<int, int>> cnt_vec{cnt.begin(), cnt.end()};
    sort(cnt_vec.begin(), cnt_vec.end(), [](auto& a, auto& b) {
        if (a.second == b.second)
            return a.first > b.first;
        else
            return a.second > b.second;
    });
    auto [num, ea] = cnt_vec.front();
    if (ea == 3)
        cout << 10000 + num * 1000;
    if (ea == 2)
        cout << 1000 + num * 100;
    if (ea == 1)
        cout << num * 100;
    return 0;
}