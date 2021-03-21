// cpp algorithm ps number 24
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, pre, now;
    bool flag = false;

    cin >> n;
    auto arr = new bool[n]{false};

    cin >> pre;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> now;
        arr[abs(now - pre)] = true;
        pre = now;
    }
    for (int i = 1; i < n;i++)
        if(!arr[i])
            flag = true;
    if(flag)
        cout << "NO";
    else
        cout << "YES";

        return 0;
}