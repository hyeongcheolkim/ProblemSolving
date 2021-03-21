//baekjoon 9020 ps

#include <iostream>
#include <array>
#include <cmath>
#include <limits>
#include <utility>
using namespace std;

int index(int n) { return n - 1; }

int main()
{
    array<bool, 10'000> arr;
    for (int i = 1; i <= arr.size(); i++)
        arr.at(index(i)) = true;

    arr.at(index(1)) = false;

    for (int i = 1; i * i <= arr.size(); i++)
        if (arr.at(index(i)) == true)
            for (int j = i * i; j <= arr.size(); j += i)
                arr.at(index(j)) = false;

    int n;
    cin >> n;
    while (n > 0)
    {

        int num = 0;
        int diff = 100000;
        int a = 0;
        int b = 0;
        cin >> num;
        a = num / 2;
        b = num / 2;

        while (1)
        {
            if (arr.at(index(a)) == true && arr.at(index(b)) == true)
                break;
            a--;
            b++;
        }

        cout << a << " " << b << endl;
        n--;
    }
    return 0;
}