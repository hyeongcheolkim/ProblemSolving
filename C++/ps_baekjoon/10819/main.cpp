//baekjoon ps 10819

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int res = numeric_limits<int>::min();
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].first = i;
        cin >> arr[i].second;
    }
    auto sum = [&]() -> int
    {
        int sum = 0;
        for (int i = 0; i < arr.size() - 1; i++)
            sum += abs(arr[i].second - arr[i + 1].second);
        return sum;
    };
    do
    {
        res = max(res, sum());
    } while (next_permutation(arr.begin(), arr.end()));
    cout << res;
    return 0;
}