#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e3;
int n, l, cnt;
vector<int> locations;
bool is_repair[mxN * 2 + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    locations.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> locations[i];
    sort(locations.begin(), locations.end());
    for (const auto& location : locations)
        if (!is_repair[location])
        {
            ++cnt;
            for (int i = location; i < location + l; ++i)
                is_repair[i] = true;
        }
    cout << cnt;
    return 0;
}