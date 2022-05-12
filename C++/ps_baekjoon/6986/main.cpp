#include <bits/stdc++.h>
using namespace std;

constexpr long double CORRECTION = 1e-8;
int n, k;
vector<long double> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    auto avg1 = accumulate(arr.begin() + k, arr.end() - k, 0.0) / (arr.size() - 2 * k);
    arr.erase(arr.begin(), arr.begin() + k);
    arr.erase(arr.end() - k, arr.end());
    long double sum = accumulate(arr.begin(), arr.end(), 0.0);
    for (int i = 0; i < k; ++i)
    {
        sum += arr.front();
        sum += arr.back();
    }
    auto avg2 = sum / (arr.size() + 2 * k);
    avg1 += CORRECTION;
    avg2 += CORRECTION;
    cout << fixed << setprecision(2) << avg1 << '\n' << avg2;
    return 0;
}