//baekjoon ps 2565

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int res = 1;
    cin >> n;
    vector<pair<int,int>> line;
    vector<int> dp(n,1);
    for (int i = 0; i < n; i++)
    {
        static int to, go;
        cin >> to >> go;
        line.push_back(make_pair(to, go));
    }
    sort(line.begin(), line.end());
    for (int i = 1; i < n;i++)
    {
        static int maxi;
        maxi = 1;
        for (int j = 0; j < i;j++)
            if (line[i].second > line[j].second)
                maxi = max(maxi,dp[j]+1);
        dp[i] = maxi;
        res = max(res, dp[i]);
    }
    cout << n-res;

    return 0;
}