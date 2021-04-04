// cpp algorithm ps number 60

#include <iostream>
#include <memory>
using namespace std;

void fnc(int lv, const int &limit, bool &flag, int *&arr);

int main()
{
    int limit;
    bool flag = false;
    cin >> limit;
    auto arr = new int[limit];
    for (int i = 0; i < limit; i++)
        cin >> arr[i];
    fnc(0, limit, flag, arr);
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

void fnc(int lv, const int &limit, bool &flag, int *&arr)
{
    static bool *tf = new bool[limit];
    static int sum1 = 0;
    static int sum2 = 0;

    if (lv == limit)
    {
        sum1 = sum2 = 0;
        for (int i = 0; i < limit; i++)
            if (tf[i])
                sum1 += arr[i];
            else
                sum2 += arr[i];
        if (sum1 == sum2)
            flag = true;
        return;
    }
    tf[lv] = true;
    fnc(lv + 1, limit, flag, arr);
    tf[lv] = false;
    fnc(lv + 1, limit, flag, arr);
    
}