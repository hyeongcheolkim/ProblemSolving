//baekjoon ps 1654

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    ll k, n;
    ll maxi = LLONG_MIN;
    cin >> k >> n;
    vector<ll> arr(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> arr[i];
        maxi = max(arr[i], maxi);
    }
    ll lt, rt, mid, sum;
    lt = 1;
    rt = maxi;
    while(lt<=rt)
    {
        sum = 0;
        mid = (lt + rt) / 2;
        for(const auto &e:arr)
            sum += e / mid;
        if(sum<n)
            rt = mid-1;
        else if (sum>=n)
            lt = mid+1;
    }
    cout << lt-1;
    return 0;
}