//baekjoon ps 2166

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    int n;
    long long int sum = 0;
    cin >> n;
    vector<long long int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i] >> arr2[i];
    arr1.push_back(arr1.front());
    for (int i = 1; i < arr1.size(); i++)
        sum += arr1[i] * arr2[i - 1];
    arr2.push_back(arr2.front());
    for (int i = 0; i < arr1.size() - 1; i++)
        sum -= arr1[i] * arr2[i + 1];
    cout << fixed;
    cout.precision(1);
    cout << abs(sum) / 2.0;
    return 0;
}