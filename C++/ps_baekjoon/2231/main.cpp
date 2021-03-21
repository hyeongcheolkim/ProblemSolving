//baekjoon 2231 ps

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n;i++)
    {
        static int sum = 0;
        static int temp = 0;
        sum = i;
        temp = i;

        while(temp!=0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        
        if(sum==n)
        {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}