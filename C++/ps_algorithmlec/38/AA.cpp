// cpp algorithm ps number 38

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto arr = new int[n];
    auto res = new int[n]{0};

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        static int num;
        static int index;
        num = 0;
        for (index = 0;num!=arr[i];index++)
            if(res[index]>(i+1)||res[index]==0)
                num++;
        while(res[index]!=0)
            index++;
        res[index] = i+1;
    }

    for (int i = 0; i < n; i++)
        cout << res[i]<< " ";

    return 0;
}