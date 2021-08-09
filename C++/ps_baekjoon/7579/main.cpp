//baekjoon ps 7579

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max() / 2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int sum = 0;
    cin >> n >> m;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        sum += arr[i].first;
    }
    for (int i = 0; i < n; i++)
        cin >> arr[i].second;
    vector<int> dp(sum + 1, INF);
    dp[0] = 0;
    for (const auto &e : arr)
    {
        int memory = e.first;
        int cost = e.second;
        for (int i = sum; i >= memory; i--)
            dp[i] = min(dp[i], dp[i - memory] + cost);
    }
    cout << *min_element(dp.begin() + m, dp.end());
    return 0;
}