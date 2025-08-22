#include <bits/stdc++.h>
using namespace std;

int n, maxi_day = -1, ret;
vector<pair<int,int>> arr;

auto cmp = [](const pair<int,int>& a, const pair<int,int>& b)
{
    return a.first < b.first;
};

priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while(n--)
    {
        int p, d;
        cin >> p >> d;
        maxi_day = max(maxi_day, d);
        arr.emplace_back(p, d);
    }
    sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int> &b){
        return a.second < b.second;
    });
    for(int today = maxi_day; today > 0; --today)
    {
        while(!arr.empty() && arr.back().second == today)
        {
            pq.push(arr.back());
            arr.pop_back();
        }

        if(!pq.empty())
        {
            ret += pq.top().first;
            pq.pop();
        }
    }
    cout << ret;
    return 0;
}