//baekjoon ps 11401

#include <iostream>
#include <map>
#include <utility>

using namespace std;
typedef unsigned long long ull;
constexpr ull M = 1000000007;

ull bfs(ull b, ull exp)
{
    if (exp == 0)
        return 1;
    ull temp = bfs(b, exp / 2) % M;
    temp = (temp * temp) % M;
    if (exp % 2 == 0)
        return temp;
    else
        return (temp * b) % M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ull n, k;
    cin >> n >> k;
    ull a = 1, b = 1, c;
    for (ull i = 1; i <= n; i++)
        a = (a * i) % M;
    for (ull i = 1; i <= k; i++)
        b = (b * i) % M;
    for (ull i = 1; i <= n - k; i++)
        b = (b * i) % M;
    c = bfs(b, M - 2);
    cout << (a * c) % M;
    return 0;
}