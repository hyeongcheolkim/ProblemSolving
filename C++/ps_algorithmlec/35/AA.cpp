// cpp algorithm ps number 35

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr_plus;
    vector<int> arr_minus;

    for (int i = 0; i < n; i++)
    {
        static int num = 0;
        cin >> num;
        if (num > 0)
            arr_plus.push_back(num);
        else if (num < 0)
            arr_minus.push_back(num);
    }

    for (const auto &e : arr_minus)
        cout << e << " ";
    for (const auto &e : arr_plus)
        cout << e << " ";
    return 0;
}