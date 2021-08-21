//baekjoon ps 2812

#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    vector<int> arr(n);
    dq.push_back(INF);
    for (int i = 0; i < n; ++i)
    {
        char input;
        cin >> input;
        arr[i] = input - '0';
    }
    for (int idx = 0; idx < arr.size(); ++idx)
    {
        while (dq.back() < arr[idx] && k)
        {
            dq.pop_back();
            --k;
        }
        dq.push_back(arr[idx]);
    }
    while(k--)
        dq.pop_back();
    for (int i = 1; i < dq.size(); ++i)
        cout << dq[i];
    return 0;
}