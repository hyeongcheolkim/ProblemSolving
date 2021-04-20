//baekjoon ps 1149

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

enum
{
    r = 1,
    g = 2,
    b = 3,
};

struct cost
{
    int r, g, b;
    int get(int index)
    {
        switch (index)
        {
        case 1:
            return r;
        case 2:
            return g;
        case 3:
            return b;
        default:
            return 0;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<cost> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i].r >> arr[i].g >> arr[i].b;
    int dp[1005][4];
    dp[1][r] = arr[1].get(r);
    dp[1][g] = arr[1].get(g);
    dp[1][b] = arr[1].get(b);
    for (int i = 2; i <= n; i++)
    {
        dp[i][r] = arr[i].get(r) + min(dp[i - 1][g], dp[i - 1][b]);
        dp[i][g] = arr[i].get(g) + min(dp[i - 1][r], dp[i - 1][b]);
        dp[i][b] = arr[i].get(b) + min(dp[i - 1][g], dp[i - 1][r]);
    }
    cout << min({dp[n][r], dp[n][g], dp[n][b]});
    return 0;
}