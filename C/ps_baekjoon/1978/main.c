//baekjoon 1978 ps

#include <stdio.h>
#include <stdlib.h>

int isprimenumber(int x);

int main()
{
    int N;
    int counter = 0;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N;i++)
    {
        int input;
        scanf("%d", &input);
        if(isprimenumber(input))
            counter++;
    }
    printf("%d", counter);
    return 0;
}

int isprimenumber(int x)
{
    int divisor_num = 0;
    for (int i = 1; i <= x;i++)
        if(x%i==0)
            divisor_num++;
    if(divisor_num==2)
        return 1;
    else
        return 0;
}