#include <bits/stdc++.h>
using namespace std;

int n, d, k, c, maxi = 0;
vector<int> arr;
unordered_map<int, int> cnt;

void update_max()
{
    maxi = max(maxi, (int)count_if(cnt.begin(), cnt.end(), [](auto& e) {
        return e.second > 0;
    }));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d >> k >> c;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < k; ++i)
        ++cnt[arr[i]];
    ++cnt[c];
    update_max();
    for (int i = 0; i < n; ++i)
    {
        --cnt[arr[i]];
        ++cnt[arr[(i + k) % n]];
        update_max();
    }
    cout << maxi;
    return 0;
}