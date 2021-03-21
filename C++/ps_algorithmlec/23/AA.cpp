// cpp algorithm ps number 23

#include <iostream>

using namespace std;

int main()
{
    int n;
    int len = 0;
    int len_max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        static int num = 500000;
        static int prior = 500000;

        prior = num;
        cin >> num;
        if (num >= prior)
            len++;
        else
        {
            if (len > len_max)
                len_max = len;
            len = 0;
        }
    }
    if (len == n - 1)
        len_max = len;

    cout << ((len_max == 0) ? len_max : len_max + 1);
    return 0;
}