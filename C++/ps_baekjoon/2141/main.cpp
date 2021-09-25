#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mxN = 1e5;
int n;
pair<ll, ll> arr[mxN];
ll total_population, accumulate_population;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
        total_population += arr[i].second;
    }
    sort(arr, arr + n);
    total_population = (total_population + 1) / 2;
    for (const auto &e : arr)
    {
        auto [pos, population] = e;
        accumulate_population += population;
        if (accumulate_population >= total_population)
        {
            cout << pos;
            break;
        }
    }
    return 0;
}