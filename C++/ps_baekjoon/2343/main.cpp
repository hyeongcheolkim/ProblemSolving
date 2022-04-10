#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> lecture;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    lecture.resize(n);
    long long lt = -1, rt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> lecture[i];
        lt = max(lt, lecture[i]);
        rt += lecture[i];
    }
    while (lt <= rt)
    {
        long long cnt = 0, acc = 0;
        long long mid = (lt + rt) / 2;
        for (int i = 0; i < n; ++i)
        {
            if (acc + lecture[i] > mid)
            {
                acc = 0;
                ++cnt;
            }
            acc += lecture[i];
        }
        if (acc != 0)
            ++cnt;
        if (cnt <= m)
            rt = mid - 1;
        else
            lt = mid + 1;
    }
    cout << lt;
    return 0;
}