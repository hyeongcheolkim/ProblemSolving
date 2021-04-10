// cpp algorithm ps number 76

#include <iostream>
#include <vector>

using namespace std;

int dfs(int n, int r, vector<vector<int>>&memo)
{
    if(memo[n][r]!=0)
        return memo[n][r];
    if(n==r || r==0)
    {
        memo[n][r] = 1;
        return 1;
    }
    return memo[n][r]=dfs(n - 1, r - 1, memo) + dfs(n - 1, r, memo);
}

int main()
{
    int n, r;
    cin >> n >> r;
    vector<vector<int>> memo(n+1,vector<int>(n+1,0));
    cout << dfs(n, r, memo);
    return 0;
}