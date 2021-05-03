//baekjoon ps 2805

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll calculate(const ll height, const vector<ll> &arr)
{
    ll sum = 0;
    ll temp;
    for (const auto &e : arr)
        if ((temp = e - height) > 0)
            sum += temp;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &e : arr)
        cin >> e;
    sort(arr.begin(), arr.end());
    ll lt, rt, mid;
    lt = 1;
    rt = arr.back();
    while (lt < rt)
    {
        mid = (lt + rt) / 2;
        if (calculate(mid, arr) < m)
            rt = mid;
        else
            lt = mid+1;
    }
    cout << rt-1;
    return 0;
}