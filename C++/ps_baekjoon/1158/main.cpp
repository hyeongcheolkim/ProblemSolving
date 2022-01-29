#include <bits/stdc++.h>
using namespace std;

int n, k;
list<int> lt, res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    lt.resize(n);
    iota(lt.begin(), lt.end(), 1);
    for (int i = 1; !lt.empty(); ++i)
    {
        if (i % k == 0)
            res.push_back(lt.front());
        else
            lt.emplace_back(lt.front());
        lt.pop_front();
    }
    cout << '<';
    for_each(res.begin(), --res.end(), [](const auto& e) {cout << e << ", "; });
    cout << res.back() << '>';
    return 0;
}