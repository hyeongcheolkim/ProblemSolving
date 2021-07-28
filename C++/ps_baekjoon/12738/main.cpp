//baekjoon ps 12738

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
    vector<int> arr(n), lis;
    lis.push_back(-INF);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        int data = arr[i];
        if (lis.back() < data)
            lis.push_back(data);
        else
        {
            auto iter = lower_bound(lis.begin(), lis.end(), data);
            *iter = data;
        }
    }
    cout << lis.size() - 1 << '\n';
    return 0;
}