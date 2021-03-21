//baekjoon 2798 ps

#include <iostream>

using namespace std;

int main()
{
    //value declare
    int n, m;
    cin >> n >> m;

    //dynamic allocate size n integer arr
    int *arr = new int[n];
    unsigned int max = 0;

    //cin cardnumber to arr
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //algorithm
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
            {
                static int sum = 0;
                sum = arr[i] + arr[j] + arr[k];
                if (max < sum && sum <= m)
                    max = sum;
            }
    
    //print answer
    cout << max;
    delete[] arr;
    return 0;
}