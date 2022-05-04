#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vector<pair<int, int>> arr;
    for (int i = 1; i <= 8; ++i)
    {
        int num;
        cin >> num;
        arr.emplace_back(num, i);
    }
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    arr.resize(5);
    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    cout << accumulate(arr.begin(), arr.end(), 0, [](int acc, auto& p) {
        return acc + p.first;
    }) << '\n';
    for (const auto& e : arr)
        cout << e.second << ' ';
    return 0;
}