#include <bits/stdc++.h>
using namespace std;
using mat = pair<int, int>;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;
vector<vector<int>> dp;
vector<mat> matrix;

int calculate_cost(mat a, mat b) { return a.first * a.second * b.second; }

int solve(int lt = 1, int rt = n)
{
    int& ret = dp[lt][rt];
    if (ret != INF)
        return ret;
    if (lt == rt)
        return ret = 0;
    if (lt + 1 == rt)
        return ret = calculate_cost(matrix[lt], matrix[rt]);
    for (int k = lt; k < rt; ++k)
    {
        mat left{matrix[lt].first, matrix[k].second};
        mat right{matrix[k + 1].first, matrix[rt].second};
        int merge_cost = calculate_cost(left, right);
        ret = min(ret, solve(lt, k) + solve(k + 1, rt) + merge_cost);
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1, vector<int>(n + 1, INF));
    matrix.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> matrix[i].first >> matrix[i].second;
    cout << solve();
    return 0;
}