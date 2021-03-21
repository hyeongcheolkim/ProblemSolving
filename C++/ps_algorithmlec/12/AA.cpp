// cpp algorithm ps number 12

#include <iostream>
#include <cmath>

unsigned int length(int n);
unsigned int total(unsigned int n);

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;

    cout << total(n);

    return 0;
}

unsigned int length(int n)
{
    int length = 0;
    for (; n != 0;n/=10)
        length++;
    return length;
}

unsigned int total(unsigned int n)
{
    int sum = 0;
    unsigned int len = length(n);

    for (unsigned int i = 1; i < len;i++)
    {
        sum += int(pow(10, i - 1) * 9)*i;
    }

    sum += (n - int(pow(10, len-1)) + 1) * len;
    return sum;
}