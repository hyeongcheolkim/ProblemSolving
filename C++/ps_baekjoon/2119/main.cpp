//baekjoon ps 2110

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll fnc(const ll &s, const vector<ll> &arr)
{
    ll cnt = 0;
    ll temp, index = 0;
    temp = arr[0];
    cnt++;
    for (; index < arr.size(); index++)

        if (arr[index] - temp >= s)
        {
            cnt++;
            temp = arr[index];
        }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, c;
    cin >> n >> c;
    vector<ll> arr(n);
    for (auto &e : arr)
        cin >> e;
    sort(arr.begin(), arr.end());
    ll lt, rt, mid;
    lt = 1;
    rt = arr.back();
    while (lt <= rt)
    {
        mid = (lt + rt) / 2;
        if (fnc(mid, arr) < c)
            rt = mid - 1;
        else
            lt = mid + 1;
    }
    cout << rt;
    return 0;
}