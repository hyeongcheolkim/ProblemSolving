// cpp algorithm ps number 34

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}