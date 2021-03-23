// cpp algorithm ps number 33

#include <iostream>
#include <algorithm>

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
        static int max_index = -1;
        static int max = arr[i];
        max = arr[i];
        for (int j = i+1; j < n; j++)
            if(arr[j]>max)
            {
                max = arr[j];
                max_index = j;
            }
        swap(arr[i], arr[max_index]);
    }
    int idx = 0;
    for (int score=0; score != 3 && idx<n;idx++)
    {
        static int temp = -1;
        if(temp != arr[idx])
            score++;
        temp = arr[idx];
    }
    cout << arr[idx-1];
    return 0;
}