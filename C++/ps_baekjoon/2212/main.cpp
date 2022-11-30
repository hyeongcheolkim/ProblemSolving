#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> sensor;
vector<int> diff;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    if (k >= n)
    {
        cout << 0;
        return 0;
    }
    sensor.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> sensor[i];
    sort(sensor.begin(), sensor.end());
    diff.reserve(sensor.size() - 1);
    for (int i = 0; i < n - 1; ++i)
        diff.push_back(sensor[i + 1] - sensor[i]);
    sort(diff.begin(), diff.end());
    cout << reduce(diff.begin(), diff.end() - k + 1, 0, plus<int>());
    return 0;
}