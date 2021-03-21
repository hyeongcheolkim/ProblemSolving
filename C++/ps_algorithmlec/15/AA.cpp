// cpp algorithm ps number 15

#include <iostream>

using namespace std;

int main()
{
    int n;
    int num = 0;
    cin >> n;
    bool *arr = new bool[n + 1];

    for (int i = 2; i <= n;i++)
        arr[i] = true;

    for (int i = 2; i*i < n;i++)
        if(arr[i]==true)
            for (int j = i+i; j <= n;j+=i)
                arr[j] = false;

    for (int i = 2; i <= n;i++)
        if(arr[i]==true)
            num++;
    cout << num;

    return 0;
}