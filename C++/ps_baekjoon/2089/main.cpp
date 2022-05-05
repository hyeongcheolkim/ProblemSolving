#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        exit(0);
    }
    while (n != 0)
    {
        if (n % -2 == 0)
        {
            res.push_back(0);
            n /= -2;
        }
        else
        {
            res.push_back(1);
            n = (n - 1) / -2;
        }
    }
    for_each(res.rbegin(), res.rend(), [](auto& e) {cout << e; });
    return 0;
}