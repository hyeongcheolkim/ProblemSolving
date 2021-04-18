// cpp algorithm ps number DP09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct jewelry
{
    int weight, cost;
};
int main()
{
    ios_base::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    vector<jewelry> data(n);
    vector<int> dp(w + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> data[i].weight >> data[i].cost;
    for (int i = 0; i < data.size(); i++)
        for (int index = data[i].weight; index <= w; index++)
            if (dp[index - data[i].weight] + data[i].cost > dp[index])
                dp[index] = dp[index - data[i].weight] + data[i].cost;
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}