// cpp algorithm ps number 26

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto arr = new int[n];
    auto res = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; i--)
    {
        static int cnt = 0;
        cnt = 0;
        for (int j = i-1; j >= 0; j--)
            if(arr[i]>arr[j])
                cnt++;
        res[i] = (i + 1) - cnt;
    }

    for (int i = 0; i < n; i++)
        cout<< res[i];

    return 0;
}