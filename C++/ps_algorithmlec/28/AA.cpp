// cpp algorithm ps number 28

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int two = 0;
    int five = 0;

    for (int i = 2; i <= n; i++)
    {
        static int temp = 0;
        temp = i;
        while (temp % 2 == 0)
        {
            temp /= 2;
            two++;
        }
        while (temp % 5 == 0)
        {
            temp /= 5;
            five++;
        }
    }

    cout << min(two, five);

    return 0;
}