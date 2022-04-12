#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0, maxi = 0, mini = INF;
    cin >> n;
    while (n--)
    {
        static int max_len = 0, min_len = 0;
        int num;
        cin >> num;
        if (num >= maxi)
        {
            maxi = num;
            ++max_len;
            res = max(res, max_len);
        }
        else
        {
            maxi = num;
            max_len = 1;
        }
        if (num <= mini)
        {
            mini = num;
            ++min_len;
            res = max(res, min_len);
        }
        else
        {
            mini = num;
            min_len = 1;
        }
    }
    cout << res;
    return 0;
}