//baekjoon ps 2568

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> lines(n), trace;
    vector<int> arr, res;
    arr.push_back(0);
    trace.reserve(n);
    for (int i = 0; i < n; i++)
        cin >> lines[i].first >> lines[i].second;
    sort(lines.begin(), lines.end());
    for (int i = 0; i < n; i++)
    {
        int idx = lines[i].first;
        int data = lines[i].second;
        if (arr.back() < data)
        {
            trace.push_back({arr.size(), idx});
            arr.push_back(data);
        }
        else
        {
            auto iter = lower_bound(arr.begin(), arr.end(), data);
            *iter = data;
            trace.push_back({iter - arr.begin(), idx});
        }
    }
    for (int i = trace.size() - 1; i >= 0; i--)
    {
        static int j = arr.size() - 1;
        if (trace[i].first == j)
            j--;
        else
            res.push_back(trace[i].second);
    }
    sort(res.begin(), res.end());
    cout << n - (arr.size() - 1) << '\n';
    for (const auto &e : res)
        cout << e << '\n';
    return 0;
}