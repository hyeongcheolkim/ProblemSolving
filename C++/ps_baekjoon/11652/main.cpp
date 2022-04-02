#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<long long, int> ea;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        long long num;
        cin >> num;
        ++ea[num];
    }
    vector<pair<long long, int>> vec_ea{ea.begin(), ea.end()};
    sort(vec_ea.begin(), vec_ea.end(), [](const auto& x, const auto& y) {
        return x.second == y.second ? x.first < y.first : x.second > y.second;
    });
    cout << vec_ea.front().first;
    return 0;
}