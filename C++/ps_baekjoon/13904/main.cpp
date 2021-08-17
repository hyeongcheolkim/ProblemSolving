//baekjoon ps 13904

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <memory.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0;
    cin >> n;
    array<pair<int, int>,1005> arr;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i].second >> arr[i].first;
    sort(arr.begin() + 1, arr.end(), greater<pair<int, int>>());
    array<bool, 1000 + 1> check;
    for (int i = 1; i <= n; ++i)
    {
        int score = arr[i].first;
        int day = arr[i].second;
        for (int idx = day; idx >= 1; --idx)
            if (!check[idx])
            {
                sum += score;
                check[idx] = true;
                break;
            }
    }
    cout << sum;
    return 0;
}