//baekjoon 1929 ps

#include <iostream>
#include <array>
using namespace std;

int index(int n) { return n - 1; }

int main()
{
    array<bool, 1'000'000> arr;
    for (int i = 1; i <= arr.size();i++)
        arr.at(index(i)) = true;

    arr.at(index(1)) = false;

    for (int i = 1; i*i <= arr.size();i++)
        if(arr.at(index(i))==true)
            for (int j = i * i; j <= arr.size();j+=i)
                    arr.at(index(j)) = false;
    
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b;i++)
        if(arr.at(index(i))==true)
            cout << i << "\n";

        return 0;
}