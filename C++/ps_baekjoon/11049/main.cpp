//baekjoon ps 11049

#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;
using matrix = pair<int, int>;

constexpr int INF = numeric_limits<int>::max();
int n, dp[501][501];
matrix arr[501];

int recursion(int lt, int rt)
{
    static auto cost = [&](matrix a, matrix b)
    { return a.first * a.second * b.second; };

    int &ret = dp[lt][rt];
    if (ret != INF)
        return ret;
    if (lt == rt)
        return 0;
    if (lt + 1 == rt)
        return ret = cost(arr[lt], arr[rt]);
    for (int k = lt; k < rt; k++)
    {
        matrix left{arr[lt].first, arr[k].second};
        matrix right{arr[k + 1].first, arr[rt].second};
        int merge_cost = cost(left, right);
        ret = min(ret, recursion(lt, k) + recursion(k + 1, rt) + merge_cost);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;
    for (auto &e : dp)
        fill(e, e + 501, INF);
    cout << recursion(1, n);
    return 0;
}