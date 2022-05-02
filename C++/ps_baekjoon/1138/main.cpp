#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vst.resize(n);
    for (int tick = 1; tick <= n; ++tick)
    {
        int num, idx;
        cin >> num;
        for (int step = 0; step <= n; ++step)
            if (count(vst.begin(), vst.begin() + step, 0) == num)
            {
                idx = step;
                break;
            }
        while (vst[idx] != 0)
            ++idx;
        vst[idx] = tick;
    }
    for (const auto& e : vst)
        cout << e << ' ';
    return 0;
}