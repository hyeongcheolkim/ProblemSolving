//baekjoon 18870 ps

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr0(n);
    for (int i = 0; i < n; i++)
        cin >> arr0[i];
    vector<int> arr = arr0;
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    for (const int &e : arr0)
        cout << lower_bound(arr.begin(), arr.end(), e) - arr.begin() << ' ';
    return 0;
}