//baekjoon ps 9184

#include <iostream>
#include <stdio.h>

using namespace std;

int arr[110][110][110];

int &memo(int a, int b, int c)
{
    return arr[a + 50][b + 50][c + 50];
}

int recursion(int a, int b, int c)
{
    if (memo(a, b, c) != 0)
        return memo(a, b, c);
    if (a <= 0 || b <= 0 || c <= 0)
        return memo(a, b, c) = 1;
    else if (a > 20 || b > 20 || c > 20)
        return memo(a, b, c) = recursion(20, 20, 20);
    else if (a < b && b < c)
        return memo(a, b, c) = recursion(a, b, c - 1) + recursion(a, b - 1, c - 1) - recursion(a, b - 1, c);
    else
        return memo(a, b, c) = recursion(a - 1, b, c) + recursion(a - 1, b - 1, c) + recursion(a - 1, b, c - 1) - recursion(a - 1, b - 1, c - 1);
}

int main()
{
    while(true)
    {
    static int a, b, c;
    cin >> a >> b >> c;
    if(a==-1 && b==-1 && c==-1)
        break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, recursion(a, b, c));
    }
    return 0;
}