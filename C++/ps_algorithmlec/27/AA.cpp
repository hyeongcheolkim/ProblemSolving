// cpp algorithm ps number 27

#include <iostream>

using namespace std;

void divide(int &num, const int &divisor, int &cnt);

int main()
{
    //input value
    int n;
    cin >> n;

    //set value
    auto arr = new bool[n + 1];
    auto cnt = new int[n + 1]{0};
    for (int i = 2; i <= n; i++)
        arr[i] = true;
    for (int i = 2; i *i <n; i++)
        for (int j = i + i; j <= n; j += i)
            arr[j] = false;

    for (int num = 2; num <= n;num++)
    {
        static int temp = 0;
        temp = num;
        for (int divisor = 2; divisor <= num;divisor++)
            if(arr[divisor])
                while(temp%divisor==0)
                {
                    temp /= divisor;
                    cnt[divisor]++;
                }
    }

        cout << n << "! = ";
    for (int i = 2; i <= n; i++)
        if (cnt[i] != 0)
            cout << cnt[i] << " ";

    return 0;
}