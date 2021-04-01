// cpp algorithm ps number 52

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 1;
    vector<int> arr;
    arr.push_back(1);

    int ptr_two = 0;
    int ptr_three = 0;
    int ptr_five = 0;

    while (cnt != n)
    {
        static int two, three, five;
        static int minimum;
        two = arr[ptr_two] * 2;
        three = arr[ptr_three] * 3;
        five = arr[ptr_five] * 5;

        minimum = min(min(two, three), five);

        if (minimum == two)
            ptr_two++;
        if (minimum == three)
            ptr_three++;
        if (minimum == five)
            ptr_five++;
        arr.push_back(minimum);
        cnt++;
    }

    cout << arr.back();
    return 0;
}