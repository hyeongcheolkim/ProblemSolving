//baekjoon ps 12865

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct item
{
    int weight;
    int cost;
}item;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<item> data(n);
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> data[i].weight >> data[i].cost;
    for (int i = 0; i < n;i++)
        for (int x = k; x >= data[i].weight;x--)
            dp[x] = max(dp[x - data[i].weight] + data[i].cost,dp[x]);
    cout << dp[k];
    return 0;
}