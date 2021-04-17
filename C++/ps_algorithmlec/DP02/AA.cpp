// cpp algorithm ps number DP02

#include <iostream>
#include <vector>

using namespace std;

int n;
int memo[50];

int dfs(int n)
{
    if(memo[n]!=0)
        return memo[n];
    return memo[n] = dfs(n - 1) + dfs(n - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    memo[1] = 1;
    memo[2] = 2;
    cout << dfs(n);
    return 0;
}