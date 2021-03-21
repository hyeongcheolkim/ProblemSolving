// cpp algorithm ps number 21

#include <iostream>

using namespace std;

int main()
{
    char a[10];
    char b[10];
    int as = 0, bs = 0;

    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < 10; i++)
        cin >> b[i];

    for (int i = 0; i < 10; i++)
        if (a[i] > b[i])
            as += 3;
        else if (a[i] < b[i])
            bs += 3;
        else
            as++, bs++;

    cout << as << " " << bs << "\n";

    if (as > bs)
        cout << "A";
    else if (as < bs)
        cout << "B";
    else if (as == bs)
    {
        static bool flag = true;
        for (int i = 9; i >= 0; i--)
            if (a[i] > b[i])
            {
                cout << "A";
                flag = false;
                break;
            }
            else if (a[i] < b[i])
            {
                cout << "B";
                flag = false;
                break;
            }
        if(flag)
            cout << "D";
    }
        
    return 0;
}