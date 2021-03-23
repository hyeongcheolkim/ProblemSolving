// cpp algorithm ps number 36

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n;i++)
    {
        static int temp = 0;
        static int j;
        temp = arr[i];
        for (j = i-1; j >=0 ;j--)
            if(temp<arr[j])
                arr[j + 1] = arr[j];
            else
                break;
        arr[j + 1] = temp;
    }

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    return 0;
}