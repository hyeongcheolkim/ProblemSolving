//baekjoon ps 1629

#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull bfs(ull a, ull b, ull c)
{
    if (b == 0)
        return 1;
    ull temp = bfs(a, b / 2, c);
    temp = temp * temp % c;
    if (b % 2 == 0)
        return temp;
    else
        return (temp * a) % c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ull a, b, c;
    cin >> a >> b >> c;
    cout << bfs(a, b, c);
    return 0;
}