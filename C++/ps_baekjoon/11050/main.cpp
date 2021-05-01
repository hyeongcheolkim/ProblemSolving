//baekjoon ps 11050

#include <iostream>

using namespace std;

int n, k;
int memo[1001][1001];
int bfs(int n, int k)
{
    if (memo[n][k] != 0)
        return memo[n][k];
    if (n == k || k == 0)
        return 1;
    return memo[n][k] = (bfs(n - 1, k) % 10007 + bfs(n - 1, k - 1) % 10007) % 10007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cout << bfs(n, k);
    return 0;
}