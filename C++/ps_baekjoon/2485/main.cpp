#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> tree[i];
    sort(tree.begin(), tree.end());
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; ++i)
        diff[i] = tree[i + 1] - tree[i];
    int _gcd = reduce(diff.begin(), diff.end(), diff.front(), [](auto acc, const auto& e) {return gcd(acc, e); });
    cout << accumulate(diff.begin(), diff.end(), 0, [&](auto acc, const auto& e) {return acc + (e / _gcd) - 1; });
    return 0;
}