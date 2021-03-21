//baekjoon 11653 ps

#include <iostream>

using namespace std;

void repeat(unsigned long long &N, int divisor)
{
    if(N%divisor==0)
    {
        cout << divisor << endl;
        N /= divisor;
        repeat(N, divisor);
    }
}

int main()
{
    unsigned long long N;
    cin >> N;

    for (int i = 2; i <= N;i++)
    {
        repeat(N, i);
    }
}