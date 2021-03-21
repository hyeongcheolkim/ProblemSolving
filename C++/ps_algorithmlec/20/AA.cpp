// cpp algorithm ps number 20

#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    auto arr_a = new int[n];
    auto arr_b = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr_a[i];
    for (int i = 0; i < n; i++)
        cin >> arr_b[i];

    for (int i = 0; i < n; i++)
    {
        if (arr_a[i] == 1)
            if (arr_b[i] == 2)
                cout << "B";
            else if (arr_b[i] == 3)
                cout << "A";
            else
                cout << "D";
        else if (arr_a[i] == 2)
            if (arr_b[i] == 1)
                cout << "A";
            else if (arr_b[i] == 3)
                cout << "B";
            else
                cout << "D";
        else if (arr_a[i] == 3)
            if (arr_b[i] == 1)
                cout << "B";
            else if (arr_b[i] == 2)
                cout << "A";
            else
                cout << "D";
    }
    return 0;
}