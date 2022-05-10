#include <bits/stdc++.h>
using namespace std;

int a, b, m;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> m;
    int decimal = 0;
    while (m--)
    {
        int num;
        cin >> num;
        decimal += num * pow(a, m);
    }
    vector<int> res;
    while (decimal)
    {
        res.push_back(decimal % b);
        decimal /= b;
    }
    for_each(res.rbegin(), res.rend(), [](auto& e) {cout << e << ' '; });
    return 0;
}