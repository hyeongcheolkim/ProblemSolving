#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> rest;

bool check(const int& cnt) { return cnt > m; }

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> l;
    rest.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> rest[i];
    rest.push_back(0);
    rest.push_back(l);
    sort(rest.begin(), rest.end());
    int lt = 0;
    int rt = l;
    while (lt + 1 < rt)
    {
        int mid = (lt + rt) / 2;
        int cnt = 0;
        for (int i = 0; i < rest.size() - 1; ++i)
        {
            int diff = rest[i + 1] - rest[i] - 1;
            cnt += diff / mid;
        }
        if (check(cnt))
            lt = mid;
        else
            rt = mid;
    }
    cout << rt;
    return 0;
}