// cpp algorithm ps number 9

#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int *arr = new int[n+1] {0};
    for (int i = 1; i <= n;i++)
        for (int j = i; j <= n;j+=i)
            arr[j]++;
    for (int i = 1; i <= n;i++)
        cout << arr[i]<<" ";

    delete []arr;

    return 0;
}