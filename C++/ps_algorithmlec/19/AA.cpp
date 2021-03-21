// cpp algorithm ps number 19

#include <iostream>

using namespace std;

int main()
{
    int n;
    int num = 0;
    cin >> n;
    auto arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        static bool flag = true;
        flag = true;
        for (int j = i + 1; j < n; j++)
            if (arr[j] >= arr[i])
            {
                flag = false;
                break;
            }
        if (flag)
            num++;
    }
    cout << num;
    return 0;
}