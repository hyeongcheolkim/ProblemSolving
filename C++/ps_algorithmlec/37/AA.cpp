// cpp algorithm ps number 37

#include <iostream>

using namespace std;

int main()
{
    int size, cnt;
    cin >> size >> cnt;

    auto arr = new int[size]{0};

    while(cnt--)
    {
        static int temp;
        static bool flag;
        static int index;

        flag = false;
        cin >> temp;

        for (int i = 0; i < size;i++)
            if(temp==arr[i])
            {
                flag = true;
                index = i;
                break;
            }
        if(flag)
        {
            if(index!=0)
            {
                for (int i = index; i >= 1;i--)
                    arr[i] = arr[i- 1];
                arr[0] = temp;
            }
        }
        else
        {
            for (int i = size-1; i >=1;i--)
                arr[i] = arr[i - 1];
            arr[0] = temp;
        }
    }
    for (int i = 0; i < size;i++)
            cout << arr[i] << " ";
    return 0;
}