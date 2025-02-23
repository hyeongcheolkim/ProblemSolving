#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
vector<int> arr;
unordered_map<int, int> vst;
deque<int> dq;
int maxi = 0, cnt = 1;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d >> k >> c;

    ++vst[c];

    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < k - 1; ++i)
        arr.push_back(arr[i]);

    for (const auto &val : arr)
    {
        if (dq.size() >= k)
        {
            if(--vst[dq.front()] == 0)
                --cnt;
            dq.pop_front();
        }
        if(vst[val]++ == 0)
            ++cnt;
        dq.push_back(val);
        maxi = max(maxi, cnt);
    }
    cout << maxi;
    return 0;
}