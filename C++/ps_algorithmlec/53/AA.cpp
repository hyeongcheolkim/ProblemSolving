// cpp algorithm ps number 53

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    while (n != 0)
    {
        arr.push_back(n % k);
        n /= k;
    }
    for (int i = arr.size() - 1; i >= 0;i--)
        printf("%X", arr[i]);
    return 0;
}