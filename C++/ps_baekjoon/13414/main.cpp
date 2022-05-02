#include <bits/stdc++.h>
using namespace std;

int k, l;
unordered_map<string, int> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> l;
    while (l--)
    {
        string num;
        cin >> num;
        vst[num] = l;
    }
    vector<pair<string, int>> vec_vst{vst.begin(), vst.end()};
    sort(vec_vst.begin(), vec_vst.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < vec_vst.size() && i < k; ++i)
        cout << vec_vst[i].first << '\n';
    return 0;
}