//baekjoon 2750 ps

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //insertion algorithm O(n^2)
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
    {
        static int cursor = 0;
        cursor = i;
        for (int j = i - 1; j >= 0;j--)
        {
            if(arr[j]>arr[cursor])
            {
                swap(arr[j], arr[cursor]);
                cursor--;
            }
            else
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<'\n';
    }
        

    return 0;
}