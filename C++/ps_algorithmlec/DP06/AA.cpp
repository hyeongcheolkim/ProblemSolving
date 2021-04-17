// cpp algorithm ps number DP06

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct brick
{
    int s, h, w;
    bool operator<(const brick &obj)const
    {
        return this->s > obj.s;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int res = INT_MIN;
    cin >> n;
    vector<brick> data(n);
    vector<int> dp(n, 0);
    for (int i = 0; i < n;i++)
        cin >> data[i].s >> data[i].h >> data[i].w;
    sort(data.begin(), data.end());

    for (int index = 0;index<n;index++)
    {
        static int max;
        max = 0;
        for (int i = 0; i < index;i++)
        {
            if(data[index].w<data[i].w)
                if(max<dp[i])
                    max = dp[i];
        }
        dp[index] = data[index].h + max;
        if(dp[index]>res)
            res = dp[index];
    }
    cout << res;

    return 0;
}