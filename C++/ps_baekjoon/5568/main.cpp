#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
set<long long> s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    do
    {
        string tmp;
        for (int i = 0; i < k; ++i)
            tmp.append(to_string(arr[i]));
        s.insert(stoll(tmp));
    } while (next_permutation(arr.begin(), arr.end()));
    cout << s.size();
    return 0;
}