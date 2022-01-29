#include <bits/stdc++.h>
using namespace std;

int n, k;
deque<int> dq, res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    dq.resize(n);
    iota(dq.begin(), dq.end(), 1);
    for (int i = 1; !dq.empty(); ++i)
    {
        if (i % k == 0)
            res.push_back(dq.front());
        else
            dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << '<';
    for_each(res.begin(), res.end() - 1, [](const auto& e) {cout << e << ", "; });
    cout << res.back() << '>';
    return 0;
}