// cpp algorithm ps number 14

#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(const unsigned int &x);
unsigned int reverse(const unsigned int &x);


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned int> arr;

    while (n--)
    {
        static unsigned int num = 0;
        static unsigned int reverse_num = 0;
        cin >> num;
        reverse_num = reverse(num);
        if(isPrime(reverse_num))
            arr.push_back(reverse_num);
    }
    for(const auto &e:arr)
        cout << e<<" ";

    return 0;
}

bool isPrime(const unsigned int &x)
{
    int n = 0;
    for (int i = 1; i <= x;i++)
        if(x%i==0)
            n++;
    if(n==2)
        return 1;
    else
        return 0;
}

unsigned int reverse(const unsigned int &x)
{
    unsigned int temp = x;
    unsigned int reverse = 0;
    for (int i = 0; temp != 0;temp/=10)
        reverse = reverse * 10 + (temp % 10);
    return reverse;
}