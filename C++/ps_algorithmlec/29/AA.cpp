// cpp algorithm ps number 29

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 0;
    for (int i = 1; i <= n;i++)
    {
        static int temp = 0;
        temp = i;
        while(temp!=0)
        {
            if(temp%10==3)
                num++;
            temp /= 10;
        }
    }
    cout << num;
    return 0;
}