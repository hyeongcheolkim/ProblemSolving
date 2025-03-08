#include <bits/stdc++.h>
using namespace std;

bool cmp(const int &a, const int &b) { return a > b; };
int n, m;
priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);
vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    arr.resize(n);

    while (m--)
        pq.push(0);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
        
    sort(arr.begin(), arr.end(), [](const int& a, const int& b){return a > b;});

    for(const auto &val : arr)
    {
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp + val);
    }

    int maxi = 0;
    while (!pq.empty())
    {
        maxi = max(maxi, pq.top());
        pq.pop();
    }
    cout << maxi;
    return 0;
}