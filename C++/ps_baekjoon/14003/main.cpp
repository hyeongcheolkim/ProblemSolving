//baekjoon ps 14003

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    constexpr int INF = numeric_limits<int>::max();
    int n;
    cin >> n;
    vector<int> arr(n), lis, res;
    vector<pair<int, int>> trace;
    lis.push_back(-INF);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        int data = arr[i];
        if (lis.back() < data)
        {
            trace.push_back({lis.size(), data});
            lis.push_back(data);
        }
        else
        {
            auto iter = lower_bound(lis.begin(), lis.end(), data);
            *iter = data;
            trace.push_back({iter - lis.begin(), data});
        }
    }
    for (int i = trace.size() - 1, j = lis.size() - 1; i >= 0; i--)
        if (trace[i].first == j)
        {
            res.push_back(trace[i].second);
            j--;
        }
    reverse(res.begin(), res.end());
    cout << lis.size() - 1 << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}