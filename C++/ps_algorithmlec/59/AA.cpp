// cpp algorithm ps number 59

#include <iostream>

using namespace std;

void fnc(int n, const int &limit)
{
    static bool arr[4]{false};
    if (n == limit + 1)
    {
        for (int i = 1; i <= limit; i++)
            if (arr[i])
                cout << i << " ";
        cout << '\n';
        return;
    }
    arr[n] = true;
    fnc(n + 1, limit);
    arr[n] = false;
    fnc(n + 1, limit);
}

int main()
{
    int n;
    cin >> n;
    fnc(1, n);
    return 0;
}