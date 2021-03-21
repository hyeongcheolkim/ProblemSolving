//baekjoon 2581 ps

#include <stdio.h>

int main()
{
    int M, N;
    int flag_min = 1;
    int flag_noprime = 1;
    int count = 0;
    int sum = 0;
    int min = 0;

    scanf("%d%d", &M, &N);

    for (int i = M; i <= N; i++)
    {
        count = 0;
        for (int x = 1; x <= i; x++)
        {
            if (i % x == 0)
                count++;
        }
        if (count == 2)
        {
            sum += i;
            flag_noprime = 0;
            if (flag_min)
            {
                min = i;
                flag_min = 0;
            }
        }
    }

    if(flag_min)
        printf("%d", -1);
    else
        printf("%d\n%d", sum, min);
    

    return 0;
}