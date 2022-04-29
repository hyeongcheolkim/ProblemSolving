#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> p;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.reserve(n);
    p.resize(n);
    for (int idx = 0; idx < n; ++idx)
    {
        int num;
        cin >> num;
        arr.emplace_back(num, idx);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i)
    {
        auto [a_i, idx] = arr[i];
        p[idx] = i;
    }
    for (const auto& e : p)
        cout << e << ' ';
    return 0;
}