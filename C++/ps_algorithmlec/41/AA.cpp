// cpp algorithm ps number 41

#include <iostream>

using namespace std;

int sum(const int &num)
{
    return (num) * (num + 1) * 0.5;
}

int main()
{
    int n;
    int repeat=0;
    cin >> n;

    int temp;
    for (int i = 2; (temp = n - sum(i))/i >= 0 ;i++)
    {
        
        if(temp%i==0)
        {
            static int j;
            for (j = 1; j < i;j++)
                cout << (j+temp/i) << " + ";
            cout << j + temp / i << " = " << n << '\n';
            repeat++;
        }
    }
    cout << repeat;
}