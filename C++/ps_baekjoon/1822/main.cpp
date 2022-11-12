#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> a, b;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (n--)
    {
        int num;
        cin >> num;
        a.insert(num);
    }
    while (m--)
    {
        int num;
        cin >> num;
        b.insert(num);
    }
    vector<int> vec_a{a.begin(), a.end()};
    vector<int> vec_b{b.begin(), b.end()};
    vector<int> diff;
    set_difference(vec_a.begin(), vec_a.end(), vec_b.begin(), vec_b.end(), inserter(diff, diff.begin()));
    cout << diff.size() << '\n';
    for (auto e : diff)
        cout << e << ' ';
    return 0;
}