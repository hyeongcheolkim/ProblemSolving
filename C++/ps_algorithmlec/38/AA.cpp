// cpp algorithm ps number 38

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto arr = new int[n];
    auto res = new int[n];

    for (int i = 0; i < n;i++)
        cin >> arr[i];
    for (int i = 0; i < n;i++)
        res[arr[i]] = i+1;
    for (int i = 0; i < n;i++)
        cout << res[i];

        return 0;
}