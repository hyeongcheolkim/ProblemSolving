//baekjoon ps 6588

#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    constexpr int SIZE = 1000000;
    const string wrong = "Goldbach's conjecture is wrong.";
    array<bool, SIZE + 1> arr;
    arr.fill(true);
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i * i <= SIZE; i++)
        if (arr[i])
            for (int j = i * i; j <= SIZE; j += i)
                arr[j] = false;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        int lt = 1;
        int rt = n - 1;
        while (++lt <= --rt)
        {
            if (arr[lt] && arr[rt])
            {
                cout << n << " = " << lt << " + " << rt << '\n';
                break;
            }
        }
    }
    return 0;
}