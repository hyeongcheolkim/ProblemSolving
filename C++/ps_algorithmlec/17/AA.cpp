// cpp algorithm ps number 17

#include <iostream>

using namespace std;

typedef struct
{
    int num;
    int sum;
} stu;

int main()
{
    int n;
    cin >> n;
    auto arr = new stu[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].num >> arr[i].sum;
        if ((arr[i].num) * (arr[i].num + 1) / 2 == arr[i].sum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}