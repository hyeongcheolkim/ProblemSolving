//baekjoon 4948 ps

#include <iostream>
#include <array>
using namespace std;

int index(int n) { return n - 1; }

int main()
{
    while(1)
    {
    int n;
    int total = 0;
    cin >> n;

    if(n==0)
       break;


    array<bool, 1'000'000> arr;
    for (int i = 1; i <= 2*n;i++)
        arr.at(index(i)) = true;

    arr.at(index(1)) = false;

    for (int i = 1; i*i <= 2*n;i++)
        if(arr.at(index(i))==true)
            for (int j = i * i; j <= 2*n;j+=i)
                    arr.at(index(j)) = false;
    
    

   
    for (int i = n+1; i <= 2*n;i++)
        if(arr.at(index(i))==true)
            total++;
    cout << total << endl;
    }
    return 0;
}