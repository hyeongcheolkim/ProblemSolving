//baekjoon ps 13172

#include <iostream>

using namespace std;
using ull = unsigned long long;
constexpr int x = 1000000007;

ull reverse(ull n)
{
    ull b = 1, digit = 1, temp = n;
    while (digit <= x - 2)
    {
        if (digit & x - 2)
            b = (b * temp) % x;
        temp = (temp * temp) % x;
        digit <<= 1;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;
    ull res = 0;
    while (m--)
    {
        int n, s;
        cin >> n >> s;
        res = (res + (s * reverse(n)) % x) % x;
    }
    cout << res << '\n';
    return 0;
}