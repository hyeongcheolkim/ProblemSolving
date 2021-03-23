// cpp algorithm ps number 32

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto arr = new int[n];

    for (int i = 0; i < n;i++)
        cin >> arr[i];

    for (int i = 0; i < n-1;i++)
    {
        static int min_index = -1;
        static int min = arr[i];
        min = arr[i];
        for (int j = i+1; j < n; j++)
            if(arr[j]<min)
            {
                min = arr[j];
                min_index = j;
            }
        swap(arr[i], arr[min_index]);
    }
    for (int i = 0; i < n;i++)
        cout << arr[i]<< " ";
            return 0;
}