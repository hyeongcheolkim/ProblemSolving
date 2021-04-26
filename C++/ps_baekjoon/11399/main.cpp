//baekjoon ps 11399

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    unsigned long long sum = 0;
    cin >> n;
    vector<unsigned long long> arr(n);
    for (auto &e:arr)
        cin >> e;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n;i++)
            sum += arr[i] * (n-i);
    cout << sum;
    return 0;
}