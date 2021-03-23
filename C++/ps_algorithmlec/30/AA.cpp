// cpp algorithm ps number 30

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int repeat = 0;
    int multiplier = 1;

    while (n != 0)
    {
        static int temp = n;

        if ((n % 10) < 3)
            repeat += (n / 10) * multiplier;
        else if ((n % 10) > 3)
            repeat += ((n / 10) + 1) * multiplier;
        else
        {
            repeat += (n / 10) * multiplier;
            repeat += temp - (n * multiplier) + 1;
        }
        n /= 10;
        multiplier *= 10;
    }
    cout << repeat;
    return 0;
}